// 题意或用途（据代码整理）：将四位年月 YYMM 或六位年月 YYYYMM 格式化为 YYYY-MM。
// 阅读要点：四位输入按前两位与 22 比较选择 19 或 20 前缀，六位输入直接在年月之间插入短横线。

#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);
    if(s.size() == 4) {
        if(s[0] > '2') {
            printf("19%c%c-%c%c", s[0], s[1], s[2], s[3]);
            return 0;
        }
        if(s[0] == '2') {
            if(s[1] < '2') printf("20%c%c-%c%c", s[0], s[1], s[2], s[3]);
            else printf("19%c%c-%c%c", s[0], s[1], s[2], s[3]);
            return 0;
        }
        printf("20%c%c-%c%c", s[0], s[1], s[2], s[3]);
        return 0;
    }
    else printf("%c%c%c%c-%c%c", s[0], s[1], s[2], s[3], s[4], s[5]);
    return 0;
}