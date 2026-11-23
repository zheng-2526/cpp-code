// 题意或用途（据代码整理）：计算 a/b 的整数部分和指定 n 位小数。
// 阅读要点：每一步把余数乘 10，商就是下一位小数，保留新余数继续，不做四舍五入。

#include <bits/stdc++.h>
using namespace std;

int a, b, n;

int main () {
    cin >> a >> b >> n;
    cout << a / b << '.';
    int t = a % b;
    for(int i = 0; i < n; i++) {
        t *= 10;
        cout << t / b;
        t %= b;
    }
    return 0;
}