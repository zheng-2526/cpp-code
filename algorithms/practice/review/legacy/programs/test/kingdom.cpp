#include <bits/stdc++.h>
using namespace std;

long long n, m, num;

int main() {
    freopen("kingdom.in", "r", stdin);
    freopen("kingdom.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> num;
    while (num--) {
        cin >> n >> m;
        long long x = (n + m) * abs(n - m);
        // cout << x << endl;
        long long ans = 0;
        ans += (x % 2 == 0) ? x / 2 - 1: (x - 1) / 2;
        // cout << ans << endl;
        if(x >= 8)
            ans += (x / 4 - 1);
        cout << ans << '\n';
    }
    return 0;
}