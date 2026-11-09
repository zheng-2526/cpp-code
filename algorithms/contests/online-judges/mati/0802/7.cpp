#include <bits/stdc++.h>
using namespace std;

int n, x, a[300005], t, ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &x);
        if(n >= x) {
            ans = n + 1 - (x + 1) / 2;
            printf("%d\n", ans);
            for(int i = 1; i <= x / 2; i++) printf("%d ", i);
            for(int i = x; i <= n; i++) printf("%d ", i);
            printf("\n");
        }
        else {
            ans = x / 2;
            printf("%d\n", ans);
            for(int i = 1; i <= x / 2; i++) printf("%d ", i);
            printf("\n");
        }
    }
}