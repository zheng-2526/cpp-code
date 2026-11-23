// 题意或用途（据代码整理）：完全背包：每种物品可重复选择，求容量内最大价值。
// 阅读要点：容量倒序并显式枚举当前类型的数量 k，所以仍允许多件。这与顺序枚举容量的常见写法不同。

#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[20001];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &w[i], &c[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 0; j--) {
            for(int k = 1; ; k++)
                if(j >= w[i] * k) dp[j] = max(dp[j], dp[j - w[i] * k] + k * c[i]);
                else break;
        }
    }
    printf("%d", dp[m]);
    return 0;
}