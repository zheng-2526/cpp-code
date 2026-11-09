#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        long long xr = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            xr ^= x;
        }
        if (xr == 0) {
            cout << "Bob\n";
        } else {
            long long need = xr & -xr;
            cout << (k >= need ? "Alice" : "Bob") << '\n';
        }
    }
    return 0;
}
