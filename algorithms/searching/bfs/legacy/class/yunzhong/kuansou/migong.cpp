// 题意或用途（据代码整理）：在以点号表示可走位置的迷宫里，求左上到右下的四向最短步数。
// 阅读要点：BFS 每扩展一层多走一步，vis 防止重复入队。
// 注意：旧代码先判是否为终点，再看地块是否可走，起终点重合也需要单独检查。

#include <bits/stdc++.h>
using namespace std;

struct nod {
    int x, y, step;
    nod(int xx = 0, int yy = 0, int ss = 0) {
        x = xx, y = yy; step = ss;
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
bool mp[1005][1005], vis[1005][1005];
queue<nod> q;

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            scanf("%c", &c);
            mp[i][j] = (c == '.');
        }
        getchar();
    }
    q.push(nod(1, 1, 0));
    while(!q.empty()) {
        nod t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx == n && ny == m) {
                printf("%d", t.step + 1);
                return 0;
            }
            if(mp[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push(nod(nx, ny, t.step + 1));
            }
        }
    }
    printf("No solution");
    return 0;
}