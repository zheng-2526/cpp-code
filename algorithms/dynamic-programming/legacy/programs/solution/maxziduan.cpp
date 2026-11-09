#include <bits/stdc++.h>
using namespace std;

int a[10005], n, ad[10005], ans = -0x3f3f3f3f;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        ad [i - 1] < 0 ? ad[i] = a[i] : ad[i] = ad[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        ans = max(ans, ad[i]);
        // printf("%d ", ad[i]);
    }
    printf("%d", ans);
    return 0;
}