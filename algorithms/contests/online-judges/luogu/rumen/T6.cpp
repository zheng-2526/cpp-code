// 题意或用途（据代码整理）：网格每格指向一个方向，从查询给出的起点一直走，求出界步数，陷入环则输出 -1。
// 阅读要点：每次查询重新标记已经访问的格子。转移完全确定，重复到达一个格子即会无限循环。

#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[105][104], ans;
bool b[105][105];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while(q--) {
        int x, y, ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                b[i][j] = false;
            }
        }
        scanf("%d%d", &x, &y);
        while(!(x == 0 || y == 0 || x == n + 1 || y == m + 1)) {
            if(b[x][y]) {
                ans = -1;
                break;
            }
            b[x][y] = true;
            ans++;
            if(a[x][y] == 1) x--;
            else if(a[x][y] == 2) x++;
            else if(a[x][y] == 3) y--;
            else y++;
        }
        printf("%d\n", ans);
    }
}