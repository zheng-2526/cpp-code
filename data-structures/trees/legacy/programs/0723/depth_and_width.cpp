#include <bits/stdc++.h>
using namespace std;
 
int a[30][4], n, d, w[31], dm, ans;
bool chi[31],pa[31];
 
void dfs(int k) {
    if(a[k][1] == 0) {
        d = max(d, dm);
        return;
    }
    dm++;
    w[dm]++;
    dfs(a[k][2]);
    dfs(a[k][3]);
    dm--;
}
 
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        chi[a[i][2]] = chi[a[i][3]] = 1;
        pa[a[i][1]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(!chi[i] && pa[i]) {
            dfs(1);
            break;
        }
    }
    for(int i = 1; i <= n; i++) {
        ans = max(ans, w[i]);
    }
    printf("%d %d", d, ans);
    return 0;
}