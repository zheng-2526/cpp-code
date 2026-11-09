#include <bits/stdc++.h>
using namespace std;

int fa[200005], n, m, x, y, z;

int find(int x) {
    if (fa[x] == x) {
        return x;
    }
        else {
        int m = find(fa[x]);
        fa[x] = m;
        return find(fa[x]);
    }
}

int main() {
    scanf("%d%d", &n, &m, &x);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> y >> z;
        fa[find(y)] = find(z);
    }
    for(int i = 1; i <= x; i++) {
        cin >> y >> z;
        if (find(y) == find(z)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}