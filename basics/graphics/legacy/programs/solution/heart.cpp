#include <SFML/Graphics.hpp>       //EasyX图形库头文件
#include <conio.h>          //控制台输入输出
#include <time.h>           //时间函数
#include <math.h>           //数学函数
#include <stdlib.h>         //标准库函数

// 定义结构体，包含坐标和颜色
struct Point {
    double x, y;
    COLORREF color;
};

// 预设颜色数组
COLORREF colors[256] = {
    RGB(255, 105, 180),  // 粉红色
    RGB(218, 112, 214),  // 紫红色
    RGB(255, 182, 193),  // 浅粉色
    RGB(238, 130, 238),  // 紫罗兰色
    RGB(255, 20, 147),   // 深粉色
    RGB(199, 21, 133),   // 中等紫罗兰红色
    RGB(255, 160, 122),  // 浅珊瑚色
};

// 屏幕尺寸
const int xScreen = 1200;
const int yScreen = 800;

// 数学常数
const double PI = 3.1415926535;
const double e = 2.71828;

// 粒子系统参数
const double average_distance = 0.162;  // 粒子平均间距
const int quantity = 506;               // 基础粒子数量
const int circles = 210;                // 扩散圈数
const int frames = 20;                  // 动画帧数

// 存储点集的数组
Point origin_points[quantity];          // 原始心形点集
Point points[quantity * circles];       // 动态粒子点集
IMAGE images[frames];                   // 动画帧缓冲区

// 坐标系转换：数学坐标系->屏幕坐标
double screen_x(double x) {
    return xScreen / 2 + x;  // 将原点移到屏幕中心
}

double screen_y(double y) {
    return yScreen / 2 - y;  // y轴翻转
}

// 生成指定范围内的随机数
int create_random(int x1, int x2) {
    if(x2 > x1)
        return rand() %(x2 - x1 + 1) + x1;
    return x1;  // 处理x2 <= x1的情况，避免未定义行为
}

// 创建粒子数据并生成动画帧
void create_data() {
    //生成原始心形点集（参数方程：笛卡尔坐标系）
    int index = 0;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for(double radian = 0.1; radian <= 2 * PI; radian += 0.005) {
        x2 = 16 * pow(sin(radian), 3);
        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);

        // 根据间距筛选点
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if(distance >= average_distance) {
            x1 = x2, y1 = y2;
            origin_points[index].x = x2;
            origin_points[index++].y = y2;
        }
    }

    // 生成动态粒子(多层扩散效果)
    index = 0;
    for(double size = 0.1, lightness = 1.4; size <= 20; size += 0.1) {
        double success_p = 1 / (1 + pow(e, 8 - size / 2));  // 概率衰减曲线
        if(lightness > 1) lightness -= 0.0025;  // 颜色亮度渐变

        for(int i = 0; i < quantity; i++) {
            if(success_p > create_random(0, 100) / 100.0) {
                COLORREF color = colors[create_random(0, 6)];
                // 颜色亮度调整
                points[index].color = RGB(
                    GetRValue(color) / lightness,
                    GetGValue(color) / lightness,
                    GetBValue(color) / lightness
                );
                // 添加随机扰动
                points[index].x = size * origin_points[i].x + create_random(-4, 4);
                points[index++].y = size * origin_points[i].y + create_random(-4, 4);
            }
        }
    }

    int points_size = index;

    // 生成各帧动画
    for(int frame = 0; frame < frames; frame++) {
        images[frame] = IMAGE(xScreen, yScreen);
        SetWorkingImage(&images[frame]);
    }
}