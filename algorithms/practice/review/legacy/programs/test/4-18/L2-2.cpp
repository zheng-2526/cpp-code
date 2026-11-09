#include <bits/stdc++.h>
using namespace std;

int n, a[100005], maxn = -1, m, x, xx;
pair<int, int> p = {1e9, -1};

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
    }
    for(xx = 1; ; xx++) {
        if(a[xx] == maxn) {
            cout << xx;
            break;
        }
    }
    for(int i = xx + 1; i <= n; i++) {
        if(a[i] == maxn) cout << ' ' << i;
    }
    cout << '\n';
    scanf("%d", &m);
    while(m--) {
        p = {1e9, 0};
        cin >> x;
        for(int i = 1; i <= n; i++) {
            if(a[i] > x) {
                if(a[i] < p.first) p = {a[i], i};
            }
        }
        cout << p.second << '\n';
    }
}