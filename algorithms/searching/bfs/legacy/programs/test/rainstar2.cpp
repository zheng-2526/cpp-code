#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF  = 0x3f3f3f3f;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int burn[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
    int x, y, t;
};

int main() {
    freopen("rainstar.in", "r", stdin);
    freopen("rainstar.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            burn[i][j] = INF;
    int M;
    if (!(cin >> M)) return 0;
    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        for (int d = 0; d < 5; ++d) {
            int nx = x + (d < 4 ? dx[d] : 0);
            int ny = y + (d < 4 ? dy[d] : 0);
            if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN) continue;
            burn[nx][ny] = min(burn[nx][ny], t);
        }
    }
    queue<Node> q;
    if (burn[0][0] == 0) {
        cout << "-1\n";
        return 0;
    }
    q.push({0, 0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (burn[cur.x][cur.y] == INF) {
            cout << cur.t << '\n';
            return 0;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN) continue;
            if (vis[nx][ny]) continue;
            if (cur.t + 1 >= burn[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny, cur.t + 1});
        }
    }
    cout << "-1\n";
    return 0;
}