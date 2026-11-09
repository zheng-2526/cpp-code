#include <bits/stdc++.h>
using namespace std;

int a[200005], n, q, l, r, ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        ans = 0;
        scanf("%d%d", &l, &r);
        for(int j = 2; j <= n; j += 2) {
            if(a[j] >= l) {
                for(int k = j + 1; k <= n; k += 2) {
                    if(a[k] <= r) {
                        if(k = j + 1) ans += a[k] - l;
                        else ans += a[k] - a[k - 1];
                    }
                    else break;
                }
            }
            break;
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}