// 题意或用途（据代码整理）：按位置奇偶分别统计字符 A，尝试求让两组 A 相等所需的交换数。
// 阅读要点：A 总数为奇数则不可能；一次有效交换会让两组数量差减少 2，因此答案是差的一半。

#include <bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i += 2) {
        if(s[i] == 'A') a++;
    }
    for(int i = 1; i < s.size(); i += 2) {
        if(s[i] == 'A') b++;
    }
    if((a + b) % 2 == 1) {
        cout << "-1";
        return 0;
    }
    cout << abs(a - b) / 2;
    return 0;
}