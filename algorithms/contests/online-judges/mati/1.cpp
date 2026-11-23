// 题意或用途（据代码整理）：将整数的十进制各位按反序输出成整数。
// 阅读要点：x % 10 取末位，x / 10 去末位。翻转后的前导零自然消失。

#include<bits/stdc++.h> 
using namespace std;

int x, y;

int main() {
    cin >> x;
    while(x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    cout << y;
    return 0;
}