// 题意或用途（据代码整理）：输出由 1 到 n 填成的所有长度为 n 的序列，允许重复。
// 阅读要点：DFS 的第 x 层只决定第 x 位，不需要使用标记；叶结点输出整条序列。

#include <bits/stdc++.h>
using namespace std;

int n, a[10];

void dfs(int x) {
    if(x == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        a[x] = i;
        dfs(x + 1);
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}