// 题目（同目录 statement_18272.pdf）：对每组 M、N 判断 M 能否被 N 整除，输出 1 或 0。
// 阅读要点：余数 M % N 为 0 表示可以整除，除数须非零。

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
