// 题意或用途（据代码整理）：输出 1 至 n 的全排列。
// 阅读要点：DFS 每层决定一个位置，用 a 标记已选数，回退时取消标记恢复现场。

#include <bits/stdc++.h>
using namespace std;

int n, num[10];
bool a[10];

void A(int t) {
    if(t == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!a[i]) {
            a[i] = true;
            num[t] = i;
            A(t + 1);
            a[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    A(1);
    return 0;
}