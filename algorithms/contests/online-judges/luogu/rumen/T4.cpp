#include <bits/stdc++.h>
using namespace std;

long long T, n, c[100], ans;

int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        ans = 0;
        ans += c[1];
        if(n >= 2) ans += (n - 1) * 2;
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j < c[i]; j++) {
                if(i * j % 10 == 6) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}