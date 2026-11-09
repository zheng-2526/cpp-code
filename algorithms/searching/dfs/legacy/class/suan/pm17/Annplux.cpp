#include <bits/stdc++.h>
using namespace std;

int n, a[10];

void dfs(int x) {
    if(x == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        a[x] = i;
        dfs(x + 1);
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}