// 题目（同目录 statement_18281.pdf）：完全图的边权是两端数值的 gcd，询问两点间能使路径最小边权最大的值。
// 阅读要点：从大到小枚举公因子，用并查集合并，记录每次合并的门槛。两点在重构树上的最近公共祖先给出首次连通的门槛。

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    const int MAXA = 1000000;
    vector<int> a(n + 1);
    vector<vector<int>> bucket(MAXA + 1);
    int maxa = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        bucket[a[i]].push_back(i);
        maxa = max(maxa, a[i]);
    }

    int max_nodes = 2 * n + 5;
    DSU dsu(max_nodes);
    vector<array<int, 2>> child(max_nodes);
    vector<int> weight(max_nodes), roots_seen;
    int tot = n;

    // 所有 d 的倍数之间的边权至少为 d，按门槛由高往低合并。
    for (int d = maxa; d >= 1; --d) {
        int base = 0;
        for (int x = d; x <= maxa; x += d) {
            for (int idx : bucket[x]) {
                int r = dsu.find(idx);
                if (!base) {
                    base = r;
                } else {
                    int rb = dsu.find(base);
                    if (rb != r) {
                        ++tot;
                        // 把本次合并建为新父节点，保留两个原连通块首次相连的门槛。
                        weight[tot] = d;
                        child[tot] = {rb, r};
                        dsu.p[rb] = dsu.p[r] = dsu.p[tot] = tot;
                        base = tot;
                    }
                }
            }
        }
    }

    int root = dsu.find(1);
    int LOG = 1;
    while ((1 << LOG) <= tot) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(tot + 1));
    vector<int> depth(tot + 1);
    vector<int> stack = {root};
    up[0][root] = 0;
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        for (int c : child[u]) {
            if (!c) continue;
            depth[c] = depth[u] + 1;
            up[0][c] = u;
            stack.push_back(c);
        }
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= tot; ++i) up[j][i] = up[j - 1][up[j - 1][i]];
    }

    // 先用倍增加深度对齐，再一起往上跳到首次会合之前。
    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; ++j) if (diff & (1 << j)) u = up[j][u];
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; --j) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    };

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << a[x] << '\n';
        } else {
            cout << weight[lca(x, y)] << '\n';
        }
    }
    return 0;
}
