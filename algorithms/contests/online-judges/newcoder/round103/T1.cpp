// 题意或用途（据代码整理）：读取非空串，末字符为 0 则输出 NO，否则输出 YES。
// 阅读要点：只检查末位，无需将长串转成整数，原题字符范围未确认。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[s.size() - 1] == '0') printf("NO");
    else printf("YES");
    return 0;
}