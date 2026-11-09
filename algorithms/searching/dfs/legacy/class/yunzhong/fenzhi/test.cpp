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