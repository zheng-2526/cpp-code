// 题意或用途（据代码整理）：若干两字符片段按尾接首组成串，从第一个片段出发求可接的最大数量。
// 阅读要点：每层尝试一个尚未使用的匹配片段，回溯时释放标记。

#include <bits/stdc++.h>
using namespace std;

int n, maxn;
char a[51][3];
bool vis[51];

void dfs(int x, int sum) {
    maxn = max(maxn, sum);
    char c = a[x][2];
    for(int i = 2; i <= n; i++) {
        if(i == x) continue;
        if(!vis[i]) {
            vis[i] = 1;
            if(a[i][1] == c) dfs(i, sum + 1);;
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        getchar();
        a[i][1] = getchar();
        a[i][2] = getchar();
    }
    dfs(1, 1);
    printf("%d", maxn);
    return 0;
}