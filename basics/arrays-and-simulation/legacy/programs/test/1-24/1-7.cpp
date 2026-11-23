// 题意或用途（据代码整理）：输入多组长度为 n 的回答序列，以 n 表示位 1、其他字符表示位 0，求按二进制编码加一的编号。
// 阅读要点：先出现的字符是高位，累加每位的权重。代码依赖输入换行和长度符合约定。

#include <bits/stdc++.h>
using namespace std;

int n, m, x[35], ans;
char c;

int main() {
    scanf("%d %d", &n, &m);
    while(m--) {
        ans = 0;
        getchar();
        for(int i = 1; i <= n; i++) {
            c = getchar();
            if(c == 'n') x[i] = 1;
            else x[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            // printf("%d ", n - i);
            ans += x[i] * pow(2, n - i);
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}