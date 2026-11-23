// 题意或用途（据代码整理）：逐次执行二进制加一，并以 32 位宽度输出每一步。
// 阅读要点：a[1] 是最低位，低位的 1 变成 0 后继续进位，遇到 0 变成 1 即结束。

#include <bits/stdc++.h>
using namespace std;

int x, a[33];

int main() {
    scanf("%d", &x);
    for(int i = 1; i <= x; i++) {
        for(int i = 1; ; i++) {
            if(a[i] == 0) {
                a[i] = !a[i];
                break;
            }
            a[i] = !a[i];
        }
        for(int i = 32; i >= 1; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}