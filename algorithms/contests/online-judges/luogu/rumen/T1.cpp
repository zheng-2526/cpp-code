// 题意或用途（据代码整理）：按输入 x 所在区间返回 0、a、b 或 t。区间分界是 60、120、240。
// 阅读要点：注意下界包含、上界排除，建议用分界值及其前一个整数手算核对。

#include <bits/stdc++.h>
using namespace std;

int x, a, b, t;

int main() {
    cin >> x >> a >> b >> t;
    if(x < 60) {
        cout << 0;
        return 0;
    }
    if(x >= 60 && x < 120) {
        cout << a;
        return 0;
    }
    if(x >= 120 && x < 240) {
        cout << b;
        return 0;
    }
    if(x >= 240) {
        cout << t;
        return 0;
    }
}