#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, t;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int mp[305][305];
queue<node> q;

int main() {
    int m, x, y;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int t;
        scanf("%d %d %d", &x, &y, &t);
        mp[x][y] = t;
    }
    for(int i = 1; i <= 300; i++) {
        mp[i][0] = mp[0][i] = 0;
    }
    node t = {0, 0, 0}, t2;
    q.push(t);
    while (!q.empty()) {
        t2 = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            bool flag = false;
            for(int i = 0; i < 4; i++) {
                if(mp[t2.x + dx[i]][t2.y + dy[i]] != t2.t) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                printf("%d", t2.t);
                return 0;
            }
            int nx = t2.x + dx[i];
            int ny = t2.y + dy[i];
            if (nx < 0 || ny < 0) continue;
            for(int i = 0; i < 4; i++) 
                if (mp[nx + dx[i]][ny + dy[i]] <= (t2.t + 1) 
                && mp[nx + dx[i]][ny + dy[i]] != 0) 
                    continue;
            q.push({nx, ny, t2.t + 1});
        }
    }
    printf("-1");
    return 0;
}