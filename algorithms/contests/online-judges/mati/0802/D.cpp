// 题意或用途（据代码整理）：读取 n，按奇偶计算一个二次计数值，n 是 3 的倍数时再扣除 2n/3。
// 阅读要点：使用 long long 保存乘积，无法从这几个公式确认原计数对象。

#include <bits/stdc++.h>
using namespace std;

long long t, n;

int main() {
    scanf("%lld", &t);
    while(t--) {
        long long ans = 0;
        scanf("%lld", &n);
        if(n & 1) ans = n * (n - 1) / 2;
        else ans = n * (n - 2) / 2;
        if(n % 3 == 0) ans -= n / 3 * 2;
        printf("%lld\n", ans);
    }
}