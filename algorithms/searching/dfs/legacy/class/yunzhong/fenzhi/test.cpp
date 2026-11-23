// 题意或用途（据代码整理）：判断四向迷宫是否有从左上到右下的可走路径。
// 阅读要点：DFS 适合判断可达性，b 标记走过的格子。全程不撤销访问标记，避免同一格反复搜索。

#include <bits/stdc++.h>
using namespace std;

bool a[15][15], b[15][15];
string s;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int nx, int ny) {
    if(nx == n && ny == m) {
        cout << "Yes";
        exit(0);
    }
    for(int i = 0; i < 4; i++) {
        nx += dx[i];
        ny += dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny]) {
            if(b[nx][ny]) {
                nx -= dx[i];
                ny -= dy[i];
                continue;
            }
            // 只判断能否到达，已探索过的格子可以全局保留标记。
            b[nx][ny] = true;
            dfs(nx, ny);
        }
        nx -= dx[i];
        ny -= dy[i];
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        for(int j = 1; j <= m; j++) {
            a[i][j] = (s[j - 1] == '.');
        }
    }
    dfs(1, 1);
    cout << "No";
    return 0;
}