#include <bits/stdc++.h>
using namespace std;

long long ans, n, zl = LLONG_MIN, zr = LLONG_MIN;

struct node{
    int l, r;
}a[2005];

bool cmp(node a, node b) {
    return a.l < b.l;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        if(a[i].l > zr) {
            ans += a[i].r - a[i].l;
            zl = a[i].l, zr = a[i].r;
            continue;
        }
        if(a[i].r > zr) {
            ans += a[i].r - zr;
            zr = a[i].r;
            continue;
        }
    }
    cout << ans;
}