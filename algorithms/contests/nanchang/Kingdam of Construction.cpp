// 题目（同目录 statement_18284.pdf）：通过翻转任意一整行或一整列，把编号矩阵变为按行递增的目标排列并输出操作。
// 阅读要点：先按行列镜像排除位置不可能到达的数字，小规模再用 BFS 记录前驱并回溯翻转操作。
// 注意：大矩阵非初始有序时直接输出 No，只覆盖小规模搜索。

#include <bits/stdc++.h>
using namespace std;

using State = vector<int>;

State apply_op(State s, int n, int m, int op, int idx) {
    if (op == 0) {
        int r = idx;
        for (int j = 0; j < m / 2; ++j) swap(s[r * m + j], s[r * m + (m - 1 - j)]);
    } else {
        int c = idx;
        for (int i = 0; i < n / 2; ++i) swap(s[i * m + c], s[(n - 1 - i) * m + c]);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        State start(n * m), target(n * m);
        for (int i = 0; i < n * m; ++i) target[i] = i + 1;
        for (int i = 0; i < n * m; ++i) cin >> start[i];

        // 单次翻转只改变一个坐标的镜像位置，因此每个数字始终局限在自己的四点集合。
        bool orbit_ok = true;
        vector<int> pos(n * m + 1);
        for (int i = 0; i < n * m; ++i) pos[start[i]] = i;
        for (int v = 1; v <= n * m; ++v) {
            int a = pos[v] / m, b = pos[v] % m;
            int x = (v - 1) / m, y = (v - 1) % m;
            bool row_ok = (a == x || a == n - 1 - x);
            bool col_ok = (b == y || b == m - 1 - y);
            if (!row_ok || !col_ok) orbit_ok = false;
        }
        if (!orbit_ok) {
            cout << "No\n";
            continue;
        }

        if (start == target) {
            cout << "Yes\n0\n";
            continue;
        }

        if (n * m <= 10) {
            queue<State> q;
            // 同一个矩阵状态只入队一次，记录从哪里来以及做了哪次翻转。
            map<State, pair<State, pair<int, int>>> pre;
            q.push(start);
            pre[start] = {State(), {-1, -1}};
            bool found = false;
            while (!q.empty() && !found) {
                State cur = q.front();
                q.pop();
                int depth = 0;
                for (State t = cur; !pre[t].first.empty(); t = pre[t].first) ++depth;
                if (depth >= 30) continue;
                for (int r = 0; r < n; ++r) {
                    State nxt = apply_op(cur, n, m, 0, r);
                    if (!pre.count(nxt)) {
                        pre[nxt] = {cur, {0, r}};
                        if (nxt == target) {
                            found = true;
                            break;
                        }
                        q.push(nxt);
                    }
                }
                for (int c = 0; c < m && !found; ++c) {
                    State nxt = apply_op(cur, n, m, 1, c);
                    if (!pre.count(nxt)) {
                        pre[nxt] = {cur, {1, c}};
                        if (nxt == target) {
                            found = true;
                            break;
                        }
                        q.push(nxt);
                    }
                }
            }
            if (pre.count(target)) {
                vector<pair<int, int>> ops;
                for (State cur = target; cur != start; cur = pre[cur].first) ops.push_back(pre[cur].second);
                reverse(ops.begin(), ops.end());
                cout << "Yes\n" << ops.size() << '\n';
                for (auto [op, idx] : ops) cout << op << ' ' << idx + 1 << '\n';
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
