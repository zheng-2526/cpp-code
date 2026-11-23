// 题意或用途（据代码整理）：给定一棵树和起点 k，输出沿边深搜进入与折返时经过的节点。
// 阅读要点：进入时输出节点，每处理完一棵孩子子树再输出当前节点，所以序列包含回程。

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