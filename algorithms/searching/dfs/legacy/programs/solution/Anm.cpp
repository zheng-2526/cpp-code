// 题意或用途（据代码整理）：从 1 至 n 选 m 个数字，依次输出所有升序组合。
// 阅读要点：x 是上一位所选，下一位必须大于 x。上界 n-(m-t) 为后续预留足够的数字。

#include <bits/stdc++.h>
using namespace std;

int n, m, num[30];
bool a[30];

void Anm(int t, int x) {
    if(t == m + 1) {
        for(int i = 1; i <= m; i++) {
            printf("%3d", num[i]);
        }
        printf("\n");
        return;
    }
    for(int i = x + 1; i <= n - (m - t); i++) {
            num[t] = i;
            Anm(t + 1, i);
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    Anm(1, 0);
    return 0;
}