// 题意或用途（据代码整理）：尝试用长除法计算大整数除以小整数的整数商。
// 阅读要点：高位到低位读取，被除数的下一位与上轮余数组成新的局部被除数。
// 注意：余数变量 t 原本未初始化，且全零商的格式需核对。

#include <bits/stdc++.h>
using namespace std;

string s;
int a[210], b, c[210];

int main() {
    cin >> s >> b;
    for(int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }
    int t;
    for(int  i = 0; i < s.size(); i++) {
        t = t * 10 + a[i];
        if(t >= b) {
            c[i] = t / b;
            t = t % b;
        }
        else {
            c[i] = 0;
        }
    }
    int index = 0;
    for(int i = 0; i < s.size(); i++) {
        if(c[i] != 0) {
            index = i;
            break;
        }
    }
    for(int i = index; i < s.size(); i++) {
        printf("%d", c[i]);
    }
    return 0;
}