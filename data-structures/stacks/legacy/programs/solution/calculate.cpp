#include <bits/stdc++.h>
using namespace std;

stack<int> a;
char op; long long x, ans = 0;

int main() {
    scanf("%d", &x);
    a.push(x % 10000);
    while(cin >> op) {
        cin >> x;
        x %= 10000;
        if(op == '*') {
            x *= a.top();
            a.pop();
            a.push(x % 10000);
        }
        else a.push(x % 10000);
    }
    while(!a.empty()){
        x = a.top();
        a.pop();
        ans += x;
    }
    printf("%d", ans % 10000);
    return 0;
}