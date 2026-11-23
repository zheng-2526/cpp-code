// 题意或用途（据代码整理）：用于练习字符串、字符分类和局部变量遮蔽。
// 阅读要点：观察字符数组与 string，及函数内变量和同名全局变量的区别。
// 注意：原文件含不完整的 find 语句，属于未完成语法草稿。

#include <bits/stdc++.h>
using namespace std;
char a[110] = "hello";

int b[10];

string s = "hel\0o", t = "world";

int main() {
    // cout << b << endl;
    // cout << b + 1 << endl;
    // cout << a << endl;
    cin >> s;
    s = ' ' + s;
    cout << s;
    s.find(" ", 3)
    s == "";
    int a = 35;
    int t = 0;
    if(s[2] >= '0'&&s[2] <= '9');
    if(s[2] >= 'a'&&s[2] <= 'z' ||s[2] >= 'A'&&s[2] <= 'Z');
    if(s[2] >= 'A'&&s[2] <= 'Z');
    return 0;
}