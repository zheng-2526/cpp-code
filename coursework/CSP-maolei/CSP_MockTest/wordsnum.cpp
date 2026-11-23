// 题意或用途（据代码整理）：对每个编号分别统计它出现在多少组、总共出现多少次。
// 阅读要点：f[j][i] 只记第 j 组是否见过编号 i，所以组内重复只影响总次数，不增加组数。

#include <bits/stdc++.h>
using namespace std;

int n, m, l, num[105][3], f[105][105];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> l;
        for(int j = 1; j <= l; j++) {
            int x; cin >> x;
            // 每次读到就累计总词频，而 f 仅表示该组是否出现。
            num[x][2]++;
            f[i][x] = 1;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            num[i][1] += f[j][i];
        }
        cout << num[i][1] << ' ' << num[i][2] << '\n';
    }
    return 0;
}