// 题意或用途（据代码整理）：检查圆括号与方括号是否匹配且顺序合法。
// 阅读要点：左括号入栈，右括号只可匹配栈顶。弹出之前判空，扫描完也必须恰好清空。

#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main() {
    char c;
    while(cin >> c) {
        if(c == '(' || c == '[') s.push(c);
        else {
            if(c == ')') {
                // 遇到右括号时先判空，再读栈顶，避免没有可配对象时访问栈。
                if(s.empty()) {
                    printf("Wrong");
                    return 0;
                }
                if(s.top() != '(') {
                    printf("Wrong");
                    return 0;
                }
                else s.pop();
            }
            if(c == ']') {
                if(s.empty()) {
                    printf("Wrong");
                    return 0;
                }
                if(s.top() != '[') {
                    printf("Wrong");
                    return 0;
                }
                else s.pop();
            }
        }
    }
    if(s.empty()) printf("Ya");
    else printf("Wrong");
    return 0;
}