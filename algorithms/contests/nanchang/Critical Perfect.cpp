// 题目（同目录 statement_18276.pdf）：可反复选一段连续音符并把每个分值加 1，使各前缀分数都落在指定区间，求最少操作数。
// 阅读要点：原分数做前缀和后，lo/hi 是额外前缀增量的上下界，y 相邻之差是每个音符增加的分。
// 注意：这份实现用有轮数上限的平滑扫描调整 y，不能仅凭注释视作已验证的最优解。

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
            // 额外分数只增不减，所以当前前缀至少要达到上一前缀的值。
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
            // 从前一位置到当前需要更多的增量时，新增差值对应开启新的区间。
            if (x > prev_x) ans += x - prev_x;
            prev_x = x;
        }
        print_int128(ans);
        cout << '\n';
    }
    return 0;
}
