// 题意或用途（据代码整理）：读入字符网格，按空格数减去固定的 n+m-1 后的奇偶输出胜者。
// 阅读要点：只统计 '.'，无需保存网格。胜负规则只能从程序输出推测。

#include <bits/stdc++.h>
using namespace std;

int x, y, a;

int main() {
    cin >> x >> y;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++){
            char c;
            cin >> c;
            if(c == '.') a++;
        }
    }
    // cout << a << ' ';
    if((a - (x + y - 1)) % 2) printf("niuniu");
    else printf("niumei");
    return 0;
}