#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<Edge> edges(m);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v;
            adj[edges[i].u].push_back(i);
            if (edges[i].v != edges[i].u) adj[edges[i].v].push_back(i);
            else adj[edges[i].v].push_back(i);
        }
        vector<int> jump(n + 1);
        iota(jump.begin(), jump.end(), 0);
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            jump[a] = b;
            jump[b] = a;
        }

        struct Frame { int state, arrival, eid, tail; };

        vector<int> candidates;
        vector<char> seen_vertex(n + 1);
        int first_nonempty = 1;
        while (first_nonempty <= n && adj[first_nonempty].empty()) ++first_nonempty;

        vector<char> handled(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (handled[i]) continue;
            if (jump[i] != i) {
                int j = jump[i];
                handled[i] = handled[j] = 1;
                if (((adj[i].size() + adj[j].size()) & 1) != 0) {
                    if (!adj[i].empty()) candidates.push_back(i);
                    if (!adj[j].empty()) candidates.push_back(j);
                }
            } else {
                handled[i] = 1;
                if ((adj[i].size() & 1) != 0) candidates.push_back(i);
            }
        }
        if (candidates.empty() && first_nonempty <= n) candidates.push_back(first_nonempty);

        vector<int> best_out;
        bool solved = false;
        for (int start : candidates) {
            vector<int> ptr(n + 1), used(m);
            vector<Frame> st, rev;
            st.push_back({start, 0, -1, 0});
            int used_cnt = 0;

            while (!st.empty()) {
                int u = st.back().state;
                while (ptr[u] < (int)adj[u].size() && used[adj[u][ptr[u]]]) ++ptr[u];
                if (ptr[u] == (int)adj[u].size()) {
                    if (st.back().eid != -1) rev.push_back(st.back());
                    st.pop_back();
                    continue;
                }
                int id = adj[u][ptr[u]++];
                if (used[id]) continue;
                used[id] = 1;
                ++used_cnt;
                int a = edges[id].u, b = edges[id].v;
                int other = (a == u && b == u) ? u : (a == u ? b : a);
                st.push_back({jump[other], other, id, u});
            }

            if (used_cnt != m) continue;
            reverse(rev.begin(), rev.end());

            vector<int> out;
            out.push_back(start);
            int cur = start;
            bool valid = true;
            vector<int> seen(m);
            for (int i = 0; i < (int)rev.size(); ++i) {
                auto e = rev[i];
                if (e.tail != cur || seen[e.eid]) {
                    valid = false;
                    break;
                }
                seen[e.eid] = 1;
                out.push_back(e.arrival);
                cur = jump[e.arrival];
                if (i + 1 < (int)rev.size() && cur != e.arrival) out.push_back(cur);
            }
            if (valid) {
                best_out.swap(out);
                solved = true;
                break;
            }
        }

        if (!solved) {
            cout << -1 << '\n';
            continue;
        }
        cout << best_out.size() << '\n';
        for (int i = 0; i < (int)best_out.size(); ++i) {
            if (i) cout << ' ';
            cout << best_out[i];
        }
        cout << '\n';
    }
    return 0;
}
