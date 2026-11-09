#include <bits/stdc++.h>
using namespace std;

int n, m, a[65], num = 0, nn;
long long t, kk = 1, sum;
void dfs(int x, int fa) {
    if(x == n-nn + 1) {
        num++;
        if(num == t - sum ) {
            for(int i = 1; i <= nn; i++) printf("a");
            printf("b");
            for(int i = 1; i <= n + m - nn - 1; i++) {
                printf("%c", a[i] ? 'a' : 'b');
            }
            exit(0);
        }
    }
    if(fa > n + m - nn - 1) return;
    for(int i = fa; i <= n + m - nn - 1; i++) {
        a[i] = 1;
        dfs(x + 1, i + 1);
        a[i] = 0;
    }
    return;
}

int main() {
    scanf("%d%d%lld", &n, &m, &t);
    sum = 1;
    for(int k = 1; k <= n+1; k++) {
        kk *= (k + n - 1);
        kk /= k;
        sum += kk;
        if(sum > t) {
            sum -= kk;
            nn = k;
            nn=n-nn;
            break;
        }
    }
    dfs(1, 1);
    return 0;
}