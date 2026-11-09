#include <bits/stdc++.h>
using namespace std;

int n;
int a[35];

void dfs(int t, int x, int m) {
    if(x == 0) {
        printf("%d=", n);
        int i = 0;
        for(i = 1; i < t - 1; i++) {
            printf("%d+", a[i]);
        }
        printf("%d\n", a[t - 1]);
    }
    for(int i = m; i <= x && i < n; i++) {
        a[t] = i;
        dfs(t + 1, x - i, i);
        a[t] = 0;
    }
    return;
}

int main() {
    scanf("%d", &n);
    dfs(1, n, 1);
    return 0;
}