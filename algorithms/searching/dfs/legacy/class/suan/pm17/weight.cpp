#include <bits/stdc++.h>
using namespace std;

int n, a[25], wei[10005], ans, cnt;
bool vis[25];

void dfs(int x) {
    if(x == n + 1) {
        wei[ans] = 1;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(x + 1);
            ans += a[i];
            vis[i] = 1;
            dfs(x + 1);
            ans -= a[i];
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt += a[i];
    }
    dfs(1);
    for(int i = 1; i <= cnt; i++) {
        if(wei[i]) printf("%d ", i);
    }
    return 0;
}