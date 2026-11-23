// 题意或用途（据代码整理）：求两个用字符串输入的非负大整数的乘积。
// 阅读要点：模拟竖式：第 i、j 位相乘累加到第 i+j 位，再向相邻更高位进位。

#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int a[1005], b[1005], c[1005];

int main(){
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.size(); i++) a[i] = s1[s1.size() - i - 1] - '0';
    for(int i = 0; i < s2.size(); i++) b[i] = s2[s2.size() - i - 1] - '0';
    for(int i = 0; i < s2.size(); i++) {
        for(int j = 0; j < s1.size(); j++) {
            // 两个数字的低位下标相加，就是竖式乘积应累加的位置。
            c[j + i] += a[j] * b[i];
            if(c[j + i] >= 10) {
                c[j + i + 1] += c[j + i] / 10;
                c[j + i] %= 10;
            }
        }
    }
    int index = 0;
    for(int i = s1.size() + s2.size(); i >= 0; i--) {
        if(c[i] != 0) {
            index = i;
            break;
        }
    }
    for(int i = index; i >= 0; i--) {
        printf("%d", c[i]);
    }
    return 0;
}