// 题意或用途（据代码整理）：读取并原样输出 n 个不含空白的字符串。
// 阅读要点：二维字符数组每行存一条以空字符结尾的 C 字符串，本文件没有做进制或编码转换。

#include <bits/stdc++.h>
using namespace std;

char s[1005][1005];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << s[i] << endl;
    }
}