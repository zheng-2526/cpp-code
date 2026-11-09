#include <bits/stdc++.h>
using namespace std;

int n, m, l, num[105][3], f[105][105];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> l;
        for(int j = 1; j <= l; j++) {
            int x; cin >> x;
            num[x][2]++;
            f[i][x] = 1;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            num[i][1] += f[j][i];
        }
        cout << num[i][1] << ' ' << num[i][2] << '\n';
    }
    return 0;
}