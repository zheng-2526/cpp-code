#include <bits/stdc++.h>
using namespace std;

void print_int128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1), pref(n + 1), lo(n + 1), hi(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            long long l, r;
            cin >> l >> r;
            long long L = l - pref[i];
            long long R = r - pref[i];
            lo[i] = max(0LL, L);
            hi[i] = R;
            if (hi[i] < lo[i]) ok = false;
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        vector<long long> y(n + 1);
        for (int i = 1; i <= n; ++i) {
            y[i] = max(y[i - 1], lo[i]);
            if (y[i] > hi[i]) ok = false;
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        bool changed = true;
        int guard = 0;
        while (changed && guard++ < n + 5) {
            changed = false;
            for (int i = 1; i < n; ++i) {
                long long left = y[i] - y[i - 1];
                long long right = y[i + 1] - y[i];
                if (right > left) {
                    long long target = (y[i - 1] + y[i + 1]) / 2;
                    long long ny = min(hi[i], max(y[i], target));
                    if (ny > y[i]) {
                        y[i] = ny;
                        changed = true;
                    }
                }
            }
            for (int i = n - 1; i >= 1; --i) {
                long long left = y[i] - y[i - 1];
                long long right = y[i + 1] - y[i];
                if (right > left) {
                    long long target = (y[i - 1] + y[i + 1] + 1) / 2;
                    long long ny = min(hi[i], max(y[i], target));
                    if (ny > y[i]) {
                        y[i] = ny;
                        changed = true;
                    }
                }
            }
        }

        __int128 ans = 0;
        long long prev_x = 0;
        for (int i = 1; i <= n; ++i) {
            long long x = y[i] - y[i - 1];
            if (x > prev_x) ans += x - prev_x;
            prev_x = x;
        }
        print_int128(ans);
        cout << '\n';
    }
    return 0;
}
