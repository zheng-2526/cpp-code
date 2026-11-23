// 题意或用途（据代码整理）：根据厂商字符、类别字符与数字选择飞机型号。
// 阅读要点：先按首字符分成 A 系、B 系与其他，再在分支内部处理 N 和数字 2。

#include <bits/stdc++.h>
using namespace std;

char a, b;
int c;

int main() {
    cin >> a >> b >> c;
    if(a == 'A') {
        if(b == 'N') cout << "A320";
        else {
            if(c == 2) cout << "A350";
            else cout << "A380";
        }
        return 0;
    }
    else if(a == 'B') {
        if(b == 'N') cout << "B737";
        else {
            if(c == 2) cout << "B787";
            else cout << "B747";
        }
        return 0;
    }
    else cout << "C919";
    return 0;
}