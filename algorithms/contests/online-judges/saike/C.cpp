// 题意或用途（据代码整理）：读取树的父节点，尝试以节点深度为条件回答查询。
// 阅读要点：t 保存孩子，dp[i] 记录深度，依赖父节点深度已计算。
// 注意：查询参数未读入，dfs 未实现，属于未完成草稿。

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