// 题目（同目录 statement_18273.pdf）：相邻同色或同点数的牌可交换，判断能否按颜色分组且每组点数非降。
// 阅读要点：异色且异点数的两张牌无法直接交换相对次序，代码逐对检查这种颜色逆序。

#include <bits/stdc++.h>
using namespace std;

int color_id(char c) {
    if (c == 'R') return 0;
    if (c == 'Y') return 1;
    if (c == 'G') return 2;
    return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(4 * n);
        for (auto &[rank, color] : a) {
            char c;
            cin >> rank >> c;
            color = color_id(c);
        }

        bool ok = true;
        for (int i = 0; i < 4 * n && ok; ++i) {
            for (int j = i + 1; j < 4 * n; ++j) {
                int ri = a[i].first, ci = a[i].second;
                int rj = a[j].first, cj = a[j].second;
                if (ci > cj && ri != rj) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
