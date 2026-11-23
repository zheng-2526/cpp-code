// 题意或用途（据代码整理）：0/1 背包：每件物品最多取一次，容量范围内求最大价值。
// 阅读要点：dp[i][j] 表示只考虑前 i 件、容量上限为 j 的价值。选与不选都从上一行转移。

#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[101][20001];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &w[i], &c[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            // 比较不选当前物品与选它两种价值，两个分支都从上一行出发。
            if(j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}