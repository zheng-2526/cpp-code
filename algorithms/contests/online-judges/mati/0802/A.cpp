// 题意或用途（据代码整理）：检查一个字符串是否恰好出现小写与大写字母中的一类。
// 阅读要点：分别记录 a-z 和 A-Z 是否出现，非字母不会设置标记。

#include <bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') a = 1;
        if(s[i] >= 'A' && s[i] <= 'Z') b = 1;
    }
    if(a + b == 1) cout << "Yes";
    else cout << "No";
}