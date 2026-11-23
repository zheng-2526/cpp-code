// 题意或用途（据代码整理）：输入 n 位二进制字符，输出对应的十进制值。
// 阅读要点：从左到右读入，每次把旧答案乘 2 加上当前位。

#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char c;

int main() {
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; i++) {
        c = getchar();
        ans = ans * 2 + (c - '0');
    }
    printf("%d\n", ans);
    return 0;
}