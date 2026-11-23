// 题意或用途（据代码整理）：读入 n，计算程序定义的 1 加上从 1 到 n 的整数和。
// 阅读要点：累加器初始为 1，因此比通常的 1+2+…+n 多 1，原题用途未确认。

# include <bits/stdc++.h>
using namespace std;

int n, ans = 1;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ans += i;
    }
    cout << ans;
    return 0;
}