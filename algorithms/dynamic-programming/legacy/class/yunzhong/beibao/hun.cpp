#include <bits/stdc++.h>
using namespace std;
 
int m, n, w[101],c[101],dp[20001], num[101];
 
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%d %d %d", &w[i], &c[i], &num[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 0; j--) {
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