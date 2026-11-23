// 题意或用途（据代码整理）：统计小写字符串中恰好出现一次的字符，按字母序输出。
// 阅读要点：用字母与 'a' 的差映射到频次数组，不依赖字符在原串中的顺序。

#include <bits/stdc++.h>
using namespace std;

string s;
int a[27];
bool flag;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) a[s[i] - 'a' + 1]++;
    for(int i = 1; i <= 26; i++) if(a[i] == 1) printf("%c", i + 'a' - 1);
    return 0;
}