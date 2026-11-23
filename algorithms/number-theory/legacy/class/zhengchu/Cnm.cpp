// 题意或用途（据代码整理）：对若干 (n,m) 查询，统计组合数表中能被给定 k 整除的位置。
// 阅读要点：用杨辉三角递推余数，再累加二维前缀计数，从而快速回答截断到 min(n,m) 的查询。

#include <bits/stdc++.h>
using namespace std;

int c[2005][2005];
int s[2005][2005];

int main() {
    int t, k;
    cin >> t >> k;
    int n, m;
    for (int i = 1; i <= 2000; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (i == j) {
                c[i][j] = 1 % k;
            }
            else if (j == 1) {
                c[i][j] = i % k;
            }
            else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            }
            if (i == j) {
                s[i][j] = s[i][j - 1];
            }
            else {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
            // 将“余数为 0”转成一个可由二维前缀和统计的标记。
            if (c[i][j] == 0) {
                s[i][j]++;
            }
        }
    }
    while (t--) {
        cin >> n >> m;
        cout << s[n][min(n, m)] << "\n";
    }
    return 0;
}