// 题意或用途（据代码整理）：从有向图的每个点开始，枚举路径上不重复顶点的走法。
// 阅读要点：vis 在递归返回时撤销，因此同一个顶点可出现在别的路径。ans 实际统计 DFS 访问次数。
// 注意：路径数可能很大，末尾的输出格式也与 long long 不匹配。

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