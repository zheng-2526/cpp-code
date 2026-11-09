#include <bits/stdc++.h>
using namespace std;

vector<int> mp[100005];
int n, k, u, v, vis[100005];

void dfs(int t) {
    vis[t] = 1;
    printf("%d ", t);
    for(int i = 0; i < mp[t].size(); i++) {
        if(vis[mp[t][i]] == 0) {
            dfs(mp[t][i]);
            printf("%d ", t);
        }
    }
    return;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs(k);
    return 0;
}