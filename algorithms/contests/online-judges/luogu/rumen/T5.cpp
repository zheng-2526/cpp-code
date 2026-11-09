#include <bits/stdc++.h>
using namespace std;

int n, a[10005][4], ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i][1]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i][2]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i][3]);
    }
    for(int i = 1; i <= n; i++) {
        ans += max(0, a[i][3] - abs(a[i][1] - a[i][2]));
    }
    printf("%d", ans);
    return 0;
}