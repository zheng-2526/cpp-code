// 题意或用途（据代码整理）：求若干数轴区间覆盖的总长度。
// 阅读要点：按左端点排序，zr 记已覆盖的最右端。新区间完全分离时加全长，部分重叠时只加露出的部分。

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
        // 只计右端超过现有覆盖范围的增量。
        if(a[i].r > zr) {
            ans += a[i].r - zr;
            zr = a[i].r;
            continue;
        }
    }
    cout << ans;
}