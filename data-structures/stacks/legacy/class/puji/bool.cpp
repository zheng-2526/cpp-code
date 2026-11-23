// 题意或用途（据代码整理）：计算由 0、1 与 !、&、或运算符构成的带括号逻辑表达式。
// 阅读要点：扫描到右括号时，弹出最内层的操作符和操作数，算出后把一个结果字符压回。

#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main() {
    char c;
    while(cin >> c) {
        if(c != ')') {
            s.push(c);
            continue;
        }
        char x1 = s.top();
        s.pop();
        char op = s.top();
        s.pop();
        if(op == '!') {
            s.pop();
            s.push((!(x1 - '0')) + '0');
            continue;
        }
        char x2 = s.top();
        s.pop();
        s.pop();
        if(op == '|') s.push(((x1 - '0') || (x2 - '0')) + '0');
        if(op == '&') s.push(((x1 - '0') && (x2 - '0')) + '0');
    }
    printf("%c", s.top());
    return 0;
}