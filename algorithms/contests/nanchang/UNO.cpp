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
