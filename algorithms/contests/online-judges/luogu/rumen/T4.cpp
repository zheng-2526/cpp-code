// 题意或用途（据代码整理）：读每一行对应的上界 c[i]，累加边界项和个位为 6 的内部乘积项。
// 阅读要点：先计入 c[1] 及其他行的固定贡献，再逐一检查 i*j % 10。
// 注意：多个 long long 变量使用了 %d，阅读时要区分算法与读入错误。

#include <bits/stdc++.h>
using namespace std;

long long T, n, c[100], ans;

int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        ans = 0;
        ans += c[1];
        if(n >= 2) ans += (n - 1) * 2;
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j < c[i]; j++) {
                if(i * j % 10 == 6) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}