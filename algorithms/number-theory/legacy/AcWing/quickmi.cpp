// 题意或用途（据代码整理）：计算 a 的 k 次方对 p 取模。
// 阅读要点：二进制拆分指数：最低位为 1 时累乘当前底数，每轮平方并右移一位。
// 注意：原实现乘法用 int，大输入需注意中间值溢出。

#include <bits/stdc++.h>
using namespace std;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        // k 的当前最低位决定是否使用这个二进制权重的幂。
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << qmi(a, b, c) << endl;
    return 0;
}