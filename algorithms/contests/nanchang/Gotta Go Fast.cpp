#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, d;
    cin >> l >> d;
    long long t[3];
    cin >> t[0] >> t[1] >> t[2];
    string s;
    cin >> s;

    const long long INF = (1LL << 62);
    vector<vector<long long>> dp(4, vector<long long>(l + 1, INF));
    dp[0][0] = 0;
    for (int used = 0; used <= 3; ++used) {
        for (int x = 0; x <= l; ++x) {
            long long cur = dp[used][x];
            if (cur == INF) continue;
            if (x < l) {
                int terrain = s[x] - '0';
                dp[used][x + 1] = min(dp[used][x + 1], cur + t[terrain]);
            }
            if (used < 3 && x < l) {
                dp[used + 1][min(l, x + d)] = min(dp[used + 1][min(l, x + d)], cur);
            }
        }
    }

    long long ans = INF;
    for (int used = 0; used <= 3; ++used) ans = min(ans, dp[used][l]);
    cout << ans << '\n';
    return 0;
}
