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