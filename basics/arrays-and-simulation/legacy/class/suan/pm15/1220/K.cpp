// 题意或用途（据代码整理）：把十进制整数各位反转，若原数为负，保留负号。
// 阅读要点：从末尾取数字依次加入结果，前导零因整数表示而省略。
// 注意：翻转或最小负数取反可能超出 long long。

#include<bits/stdc++.h>
using namespace std;

long long x, a;

int main() {
    cin >> x;
    if(x < 0) {
        cout << '-';
        x = -x;
    }
    while(x != 0) {
        a *= 10;
        a += x % 10;
        x /= 10;
    }
    cout << a;
    return 0;
}