// 题意或用途（据代码整理）：把正整数 n 拆成至少两个正整数之和，按非降顺序输出各拆法。
// 阅读要点：x 是剩余和，m 是下一项的下界。候选从 m 开始，避免同一拆法按不同顺序重复输出。

#include <bits/stdc++.h>
using namespace std;

int n;
int a[35];

void dfs(int t, int x, int m) {
    if(x == 0) {
        printf("%d=", n);
        int i = 0;
        for(i = 1; i < t - 1; i++) {
            printf("%d+", a[i]);
        }
        printf("%d\n", a[t - 1]);
    }
    for(int i = m; i <= x && i < n; i++) {
        a[t] = i;
        dfs(t + 1, x - i, i);
        a[t] = 0;
    }
    return;
}

int main() {
    scanf("%d", &n);
    dfs(1, n, 1);
    return 0;
}