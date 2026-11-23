// 题目（同目录 statement_18280.pdf）：四层叠塔沿轨道前进，不同地形耗时不同，可零耗时前跳并减少一层，求顶层到终点的最短时间。
// 阅读要点：dp[used][x] 是已前跳 used 次到达 x 的最少耗时，每个状态可步行一格或消耗一次前跳。

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
            // 步行使用下一格的地形耗时，前跳则直接转移到 used 更大的一层。
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
