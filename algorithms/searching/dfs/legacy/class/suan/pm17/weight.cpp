// 题意或用途（据代码整理）：给定砝码重量，枚举能用若干个砝码凑出的不同正重量。
// 阅读要点：递归维护当前总重，wei 只记录重量是否出现，可合并重复结果。
// 注意：这个实现会重复枚举，学习时可思考按砝码下标逐一决定选或不选。

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