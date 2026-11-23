// 题意或用途（据代码整理）：求十进制大整数乘一个小整数。
// 阅读要点：倒序存数字让低位下标较小，逐位乘，再向高位传递进位。

#include <bits/stdc++.h>
using namespace std;

string s;
int a[250], b;

int main() {
    cin >> s >> b;
    for(int i = 0; i < s.size(); i++) {
        a[i] = s[s.size() - i - 1] - '0';
    }
    for(int i = 0; i < s.size(); i++) {
        a[i] *= b;
    }
    for(int i = 0; i < s.size() + 4; i++) {
        if(a[i] >= 10) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
    int index = 0;
    for(int i = s.size() + 4; i >= 0; i--) {
        if(a[i] != 0) {
            index = i;
            break;
        }
    }
    for(int i = index; i >= 0; i--) {
        printf("%d", a[i]);
    }
    return 0;
}