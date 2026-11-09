#include<bits/stdc++.h>
using namespace std;

int n, a[100005], ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    while(n > 3) {
        ans += min(a[2] * 2 + a[1] + a[n], a[n - 1] + 2 * a[1] + a[n]);
        n -= 2;
    }
    if(n == 3) {
        ans += a[1] + a[2] + a[3];
    }
    if(n == 2) {
        ans += a[2];
    }
    if(n == 1) {
        ans += a[1];
    }
    printf("%d", ans);
    return 0;
}