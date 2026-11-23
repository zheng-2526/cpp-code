// 题意或用途（据代码整理）：生成一个大规模压力测试文件 zyz.in。
// 阅读要点：先写数据规模，再写周期数组与大量固定的查询对，输出重定向会覆盖同名文件。

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("zyz.in", "w", stdout);
    cout << 100000 << ' ' << 100000 << '\n';
    for(int i = 1; i <= 100000; i++) {
        cout << i % 100 + 1 << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= 100000; i++) cout << 100000 << ' ' << 100000 << '\n';
}