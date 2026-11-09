#include <bits/stdc++.h>
using namespace std;

using Arr = array<int, 64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> val(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        int mask = 0;
        while (k--) {
            int x;
            cin >> x;
            mask |= 1 << (x - 1);
        }
        val[i] = mask;
    }

    vector<int> parent(n + 1), order;
    order.reserve(n);
    vector<int> st = {1};
    parent[1] = -1;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        order.push_back(u);
        for (int v : g[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            st.push_back(v);
        }
    }

    vector<char> is_leaf(n + 1);
    int total_leaves = 0;
    for (int i = 1; i <= n; ++i) {
        is_leaf[i] = (g[i].size() == 1);
        total_leaves += is_leaf[i];
    }

    vector<Arr> down_inc(n + 1), down_exc(n + 1), up_inc(n + 1), up_exc(n + 1);
    for (int u = 1; u <= n; ++u) {
        down_inc[u].fill(0);
        down_exc[u].fill(0);
        up_inc[u].fill(0);
        up_exc[u].fill(0);
    }

    for (int it = n - 1; it >= 0; --it) {
        int u = order[it];
        if (is_leaf[u]) {
            down_inc[u][val[u]]++;
            down_exc[u][0]++;
        }
        for (int v : g[u]) {
            if (parent[v] != u) continue;
            for (int mask = 0; mask < 64; ++mask) {
                if (down_inc[v][mask]) down_inc[u][mask | val[u]] += down_inc[v][mask];
                if (down_exc[v][mask]) down_exc[u][mask | val[u]] += down_exc[v][mask];
            }
        }
    }

    vector<long long> answer(n + 1);
    for (int u : order) {
        Arr all_inc{}, all_exc{};
        all_inc.fill(0);
        all_exc.fill(0);

        for (int mask = 0; mask < 64; ++mask) {
            all_inc[mask] += up_inc[u][mask];
            all_exc[mask] += up_exc[u][mask];
        }
        if (is_leaf[u]) {
            all_inc[val[u]]++;
            all_exc[0]++;
        }
        for (int v : g[u]) {
            if (parent[v] != u) continue;
            for (int mask = 0; mask < 64; ++mask) {
                if (down_inc[v][mask]) all_inc[mask | val[u]] += down_inc[v][mask];
                if (down_exc[v][mask]) all_exc[mask | val[u]] += down_exc[v][mask];
            }
        }

        Arr total_inc = all_inc;
        Arr total_exc = all_exc;
        if (is_leaf[u]) {
            total_inc[val[u]]--;
            total_exc[0]--;
        }

        int forced = 0;
        for (int mask = 0; mask < 64; ++mask) {
            if (total_exc[mask] > 0) forced |= mask;
        }
        int keep = 0;
        for (int mask = 0; mask < 64; ++mask) {
            if ((mask | forced) == mask) keep = max(keep, total_inc[mask]);
        }
        int leaves = total_leaves - (is_leaf[u] ? 1 : 0);
        answer[u] = leaves - keep;

        for (int v : g[u]) {
            if (parent[v] != u) continue;
            Arr excl_inc = all_inc;
            Arr excl_exc = all_exc;
            for (int mask = 0; mask < 64; ++mask) {
                if (down_inc[v][mask]) excl_inc[mask | val[u]] -= down_inc[v][mask];
                if (down_exc[v][mask]) excl_exc[mask | val[u]] -= down_exc[v][mask];
            }

            for (int mask = 0; mask < 64; ++mask) {
                if (excl_inc[mask]) up_inc[v][mask | val[v]] += excl_inc[mask];
                if (excl_exc[mask]) up_exc[v][mask | val[v]] += excl_exc[mask];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
