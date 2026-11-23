// 题意或用途（据代码整理）：用二进制拆分计算 a*b 对 c 取模。
// 阅读要点：逐位扫描乘数 b，每次只做加法和翻倍。
// 注意：翻倍本身仍可能超出 long long，能否使用取决于输入范围。

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sch(LL a, LL b, LL c) {
    LL res = 0;
    while(b) {
        if(b & 1) res = (res + a) % c;
        a = a * 2 % c;
        b >>= 1;
    }
    return res;
}

int main() {
    LL a, b, c;
    cin >> a >> b >> c;
    cout << sch(a, b, c) << endl;
    return 0;
}