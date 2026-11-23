// 题意或用途（据代码整理）：混合背包的件数枚举版本，num[i] 为 0 时允许无限取，否则最多取给定数量。
// 阅读要点：容量倒序，每次显式枚举当前种类取 k 件。此实现的数量含义以代码分支为准。

#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[20001], num[101];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d %d", &w[i], &c[i], &num[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 0; j--) {
            // 为当前种类枚举 k 件。0 表示题设约定的不限件数。
            if(num[i] == 0) {
                for(int k = 1;; k++)
                    if(j >= w[i] * k) dp[j] = max(dp[j], dp[j - w[i] * k] + k * c[i]);
                    else break;
            }
            else {
                for(int k = 1; k <= num[i]; k++)
                    if(j >= w[i] * k) dp[j] = max(dp[j], dp[j - w[i] * k] + k * c[i]);
                    else break;
            }
        }
    }
    printf("%d", dp[m]);
    return 0;
}