#include <bits/stdc++.h>
using namespace std;

int n, c, a[200005], ans, l, r;

int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        l = r + 1, r = l;
        while(l <= i) {
            if(a[l] + c < a[i]) continue;
            else {
                for(r = l; r <= i; r++) {
                    if(a[r] + c > a[i]) {
                        break;
                    }
                }
                break;
            }
        }
        ans += (r - l);
    }
    printf("%d\n", ans);
    return 0;
}