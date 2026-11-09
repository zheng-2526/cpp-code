#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 1;

void dfs(int x) {
    if(x <= k) return;
    if((x - k) % 2 == 0) {
        ans++;
        dfs((x - k) >> 1);
        dfs(((x - k) >> 1) + k);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    dfs(n);
    printf("%d", ans);
    return 0;
}