// 题意或用途（据代码整理）：读入非零数，输出其中最高的 2 的幂因子，输入 0 结束。
// 阅读要点：每除一次 2 就累计一次指数，输出 1 左移该指数的结果。

#include <bits/stdc++.h>
using namespace std;

int a;

int main() {
    while(1) {
        scanf("%d", &a);
        if(a == 0) break;
        int x = 0;
        while(!(a % 2)) {
            a /= 2;
            x++;
        }
        printf("%d\n", (1 << x));
    }
    return 0;
}