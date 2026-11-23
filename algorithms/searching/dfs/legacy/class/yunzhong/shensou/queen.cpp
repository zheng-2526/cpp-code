// 题意或用途（据代码整理）：在 n×n 棋盘逐行放皇后，输出前三种摆法及总方案数。
// 阅读要点：列号、行减列、行加列分别识别三类冲突。放置时设标记，回溯时清除。

#include <bits/stdc++.h>
using namespace std;

bool l[15], z[30], f[30];
int num[15], ans, n;

void queen(int x) {
    if(x == n + 1) {
        ans++;
        if(ans <= 3) {
            for(int i = 1; i <= n; i++) {
                cout << num[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        // 同一斜线上的格子拥有相同的行减列或行加列值。
        if(!l[i] && !z[x - i + n] && !f[x + i]) {
            l[i] = z[x - i + n] = f[x + i] = true;
            num[x] = i;
            queen(x + 1);
            l[i] = z[x - i + n] = f[x + i] = false;
        }
    }
}

int main() {
    cin >> n;
    queen(1);
    cout << ans;
    return 0;
}