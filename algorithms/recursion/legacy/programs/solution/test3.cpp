// 题意或用途（据代码整理）：输出标准汉诺塔从 a 柱搬到 c 柱的每一步。
// 阅读要点：递归参数的顺序为起点、辅助、终点。先搬小盘到辅助柱，再搬最大盘，最后把小盘移到目标。

#include <bits/stdc++.h>
using namespace std;

int n;

void hp(int x, char a, char b, char c) {
    if(x == 1) {
        cout << a << "->" << 1 << "->" << c << '\n';
        return;
    }
    // 第一步先把上面的小盘从 a 搬到辅助柱 b，此时目标柱 c 临时充当辅助。
    hp(x - 1, a, c, b);
    cout << a << "->" << x << "->" << c << '\n';
    hp(x - 1, b, a, c);
}

int main() {
    cin >> n;
    hp(n, 'a', 'b', 'c');
}