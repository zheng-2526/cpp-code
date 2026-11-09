#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[101][20001];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &w[i], &c[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}