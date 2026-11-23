// 题意或用途（据代码整理）：计算 x/y² 并保留一位小数，按是否超过 25 输出题面规定的文字。
// 阅读要点：比较使用未四舍五入的计算值，y 须非零。

#include <bits/stdc++.h>
using namespace std;

double x, y, ans;

int main() {
    scanf("%lf%lf", &x, &y);
    ans = x / (y * y);
    ans > 25 ? printf("%.1lf\nPANG", ans) : printf("%.1lf\nHai Xing", ans);
    return 0;
}