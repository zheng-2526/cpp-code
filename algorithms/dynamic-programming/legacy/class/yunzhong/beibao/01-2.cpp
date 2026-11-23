// 题意或用途（据代码整理）：0/1 背包的一维压缩版本。
// 阅读要点：容量从大到小枚举，保证 dp[j-w[i]] 仍来自处理当前物品之前，避免同一件被取多次。

#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[20001];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &w[i], &c[i]);
    for(int i = 1; i <= n; i++) {
        // 剩余容量较小，倒序下它还没有被当前物品更新。
        for(int j = m; j >= 0; j--) {
            if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    printf("%d", dp[m]);
    return 0;
}