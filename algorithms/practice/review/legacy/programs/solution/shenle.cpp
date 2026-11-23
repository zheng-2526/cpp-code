// 题意或用途（据代码整理）：输入 n、m，构造 m 行二元组：前 m-1 行第二项为 0，末行为 n-m+1 和 1。
// 阅读要点：前段逐号输出，末项单独处理，暂无法确认构造所满足的原题性质。

#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i < m; i++) {
        cout << i << " 0\n";
    }
    cout << n - m + 1 << " 1";
    return 0;
}