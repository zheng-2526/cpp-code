#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXB = 1500;
const int INF  = 0x3f3f3f3f;

int N, S = 0;
int A[MAXN], B[MAXN];
vector<int> member[4];
int dp[4][MAXN * MAXB];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i] >> B[i];
        member[A[i]].push_back(B[i]);
        S += B[i];
    }
    if (S % 3 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    const int T = S / 3;
    for (int k = 1; k <= 3; ++k) {
        fill(dp[k], dp[k] + T + 1, INF);
        dp[k][0] = 0;
        for (int b : member[k]) {
            for (int v = T; v >= b; --v) {
                if (dp[k][v - b] != INF)
                    dp[k][v] = min(dp[k][v], dp[k][v - b] + 1);
            }
        }
    }
    int ans = INF;
    for (int v1 = 0; v1 <= T; ++v1) {
        if (dp[1][v1] == INF) continue;
        for (int v2 = 0; v2 <= T; ++v2) {
            if (dp[2][v2] == INF) continue;

            int v3 = -(v1 + v2);
            if (v3 < 0) v3 = -v3;
            if (v3 > T || dp[3][v3] == INF) continue;

            ans = min(ans, dp[1][v1] + dp[2][v2] + dp[3][v3]);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
    return 0;
}