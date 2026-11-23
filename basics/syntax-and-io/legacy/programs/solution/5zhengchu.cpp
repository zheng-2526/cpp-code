// 题意或用途（据代码整理）：判断输入的两个整数中是否有至少一个能被 5 整除。
// 阅读要点：逻辑或连接两个余数为 0 的条件，一个成立就输出 Yes。

#include <bits/stdc++.h>
using namespace std;

long long a, b;

int main() {
    cin >> a >> b;
    if(a % 5 == 0 || b % 5 == 0) cout << "Yes";
    else cout << "No";
    return 0;
}