// 题意或用途（据代码整理）：计算只有加法与乘法的表达式，输出结果对 10000 的余数。
// 阅读要点：乘法立即与栈顶合并，遇加号将新项入栈，最后求各乘积项之和。
// 注意：long long 变量用 %d 读入与输出，历史版本存在格式错误。

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