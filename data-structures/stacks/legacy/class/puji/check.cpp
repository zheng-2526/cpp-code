#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main() {
    char c;
    while(cin >> c) {
        if(c == '(' || c == '[') s.push(c);
        else {
            if(c == ')') {
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