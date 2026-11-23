// 题目（同目录 statement_18274.pdf）：有向道路每天增加，询问最早在哪一天可以从 s 恰好走 w 条边到 t。
// 阅读要点：矩阵元素记可用日期，拼接两段取较晚的日期，枚举中转点取最早日期。用矩阵快速幂计算恰好 w 步。

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

using Matrix = vector<vector<int>>;

Matrix multiply(const Matrix &a, const Matrix &b) {
    int n = (int)a.size();
    Matrix c(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            int aik = a[i][k];
            if (aik == INF) continue;
            for (int j = 0; j < n; ++j) {
                // 前半段和后半段都可走时整条路线才可走，所以拼接取较晚日期。
                int v = max(aik, b[k][j]);
                if (v < c[i][j]) c[i][j] = v;
            }
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Matrix edge(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edge[u][v] = min(edge[u][v], 0);
    }

    int k;
    cin >> k;
    for (int day = 1; day <= k; ++day) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        edge[x][y] = min(edge[x][y], day);
    }

    int q;
    long long w;
    cin >> q >> w;

    Matrix ans(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) ans[i][i] = 0;
    Matrix base = edge;
    while (w > 0) {
        // 每一位为 1 就接上对应长度的路线，最终拼出的步数恰好为 w。
        if (w & 1LL) ans = multiply(ans, base);
        w >>= 1LL;
        if (w) base = multiply(base, base);
    }

    while (q--) {
        int s, t;
        cin >> s >> t;
        --s; --t;
        cout << (ans[s][t] == INF ? -1 : ans[s][t]) << '\n';
    }
    return 0;
}
