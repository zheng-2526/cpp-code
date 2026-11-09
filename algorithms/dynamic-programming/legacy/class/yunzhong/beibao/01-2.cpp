#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[20001];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &w[i], &c[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 0; j--) {
            if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    printf("%d", dp[m]);
    return 0;
}