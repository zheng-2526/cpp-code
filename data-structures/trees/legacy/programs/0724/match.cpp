// 题意或用途（据代码整理）：读入 2^n 位选手的能力值，两两淘汰，输出决赛负者的原编号。
// 阅读要点：用完全二叉树自底向上计算，保存每场获胜者的分数与编号。两位决赛选手编号之和减冠军编号得到亚军。

#include<bits/stdc++.h>
using namespace std;

int a[1024], b[1024], n;

int main() {
    cin >> n;
    int x = pow(2, n);
    int j = 1;
    for (int i = pow(2, n); i <= pow(2, n + 1) - 1; i++) {
        cin >> a[i];
        b[i] = j;
        j++;
    }
    while(n--) {
        for(int i = pow(2, n); i <= pow(2, n + 1) - 1; i++) {
            a[i] = max(a[2 * i], a[2 * i + 1]);
            a[2 * i] > a[2 * i + 1] ? b[i] = b[2 * i] : b[i] = b[2 * i + 1];
        }
    }
    cout << b[2] + b[3] - b[1];
    return 0;
}