// 题意或用途（据代码整理）：读入各路段长度、单位覆盖距离 d 及沿途费用，程序尝试累计覆盖总成本。
// 阅读要点：v[i] 保存走到当前位置前见过的最低费用，r 表示上一段没有用完的距离，向上取整求补足当前段需购买的份数。

#include <bits/stdc++.h>
using namespace std;

long long n, d, x[100005], v[100005], a, r, ans;

int main() {
    cin >> n >> d;
    for(int i = 1; i < n; i++) {
        cin >> x[i];
    }
    cin >> v[1];
    for(int i = 2; i <= n; i++) {
        cin >> a;
        v[i] = a > v[i - 1] ? v[i - 1] : a;
    }
    for(int i = 1; i < n; i++) {
        int xx = ceil(1.0 * (x[i] - r) / d);
        ans += xx * v[i];
        r = xx * d - (x[i] - r);
    }
    cout << ans;
}