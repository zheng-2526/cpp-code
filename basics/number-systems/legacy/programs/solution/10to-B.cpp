// 题意或用途（据代码整理）：将整数 a 按底数 b 转换，代码尤其处理负进制的余数。
// 阅读要点：逐次除以 b，若余数为负，就在负底数情形下调整余数与商，使数字非负。输出按高位到低位排列。

#include <bits/stdc++.h>
using namespace std;

int a, b, ans[10005], ls;

int main() {
    scanf("%d%d", &a, &b);
    printf("%d=", a);
    while(a != 0) {
        ans[++ls] = a % b;
        a /= b;
        if(ans[ls] < 0) {
            ans[ls] -= b;
            a++;
        }
    }
    for(int i = ls; i > 0; i--) {
        if(ans[i] < 10) printf("%d", ans[i]);
        else printf("%c", ans[i] - 10 + 'A');
    }
    printf("(base%d)", b);
    return 0;
}