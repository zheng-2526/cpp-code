// 题意或用途（据代码整理）：若干轮分别加 a、减 b，求从 0 开始的累计净值曾到达的最高点。
// 阅读要点：逐轮更新当前量 x 与最大值 ans，最后只输出最大值。

#include <bits/stdc++.h>
using namespace std;

int x, n, a, b, ans;

int main() {
    cin >> n;
    while(n--) {
        cin >> a >> b;
        x = x + a - b;
        ans = max(ans, x);
    }
    cout << ans;
    return 0;
}