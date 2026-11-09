#include <bits/stdc++.h>
using namespace std;

int n, t, m;
bool vis[2005];
vector<int> s[2005];
long long ans = 0;

void dfs(int x) {
    ans++;
    vis[x] = 1;
    for(int i = 0; i < s[x].size(); i++) {
        if(!vis[s[x][i]]) dfs(s[x][i]);
    }
    vis[x] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        s[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        dfs(i);
    }
    printf("%d", ans);
    return 0;
}