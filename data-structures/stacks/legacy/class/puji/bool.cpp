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