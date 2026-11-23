// 题目（同目录 statement_18279.pdf）：两人轮流从某个数中减去 x，下一步的上限改为 x，选 0 当场输，判断先手能否获胜。
// 阅读要点：把所有数异或。异或为 0 时直接判后手胜，否则取最低置位 xr & -xr，与当前上限比较。

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        long long xr = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            xr ^= x;
        }
        if (xr == 0) {
            cout << "Bob\n";
        } else {
            long long need = xr & -xr;
            cout << (k >= need ? "Alice" : "Bob") << '\n';
        }
    }
    return 0;
}
