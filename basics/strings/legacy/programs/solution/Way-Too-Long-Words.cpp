// 题意或用途（据代码整理）：把长度超过 10 的单词写成首字母、内部字符数、末字母，其余原样输出。
// 阅读要点：内部字符数为总长度减 2。用 getline 逐行读取字符串。

#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
    scanf("%d", &n);
    getchar();
    while(n--) {
        getline(cin, s);
        if(s.size() > 10)
            printf("%c%d%c\n", s[0], s.size() - 2, s[s.size() - 1]);
        else cout << s << '\n';
    }
    return 0;
}