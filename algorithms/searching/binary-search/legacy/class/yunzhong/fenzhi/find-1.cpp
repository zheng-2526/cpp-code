// 题意或用途（据代码整理）：给定升序序列，查找目标 x 并输出其一个一基下标，找不到输出 -1。
// 阅读要点：保持目标若存在就处于闭区间 [l,r]，比较中点后排除不可能的一边。

#include <bits/stdc++.h>
using namespace std;

int a[10005], n, x;

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m] == x) {
            cout << m;
            return 0;
        }
        if(x < a[m]) r = m - 1;
        else l = m + 1;
    }
    cout << -1;
    return 0;
}