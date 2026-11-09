#include <bits/stdc++.h>
using namespace std;

int n, q, dp[200005];
vector<int> t[200005];



int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        t[x].push_back(i);
        dp[i] = dp[x] + 1;
    }
    scanf("%d", &q);
    for(int i = 1; i <= n; i++) {
        int u, v;
        if(dp[u] > v) {
            printf("0\n");
            continue;
        }
        dfs(1, 1);
    }
}