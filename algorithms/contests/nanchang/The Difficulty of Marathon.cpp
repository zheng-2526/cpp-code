#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        cout << (M % N == 0 ? 1 : 0) << '\n';
    }
    return 0;
}
