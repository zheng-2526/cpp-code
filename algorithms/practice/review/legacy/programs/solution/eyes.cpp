// 题意或用途（据代码整理）：从 zyz1.in 读取两个整数，按是否相等在 x+1 和 min(x,y)+2 中选一个结果。
// 阅读要点：这是与批量数据脚本同组的单例计算，公式的原题背景未确认。

#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    freopen("zyz1.in", "r", stdin);
    cin >> x >> y;
    cout << ((x == y) ? (x + 1) : (min(x, y) + 2));
    return 0;
}