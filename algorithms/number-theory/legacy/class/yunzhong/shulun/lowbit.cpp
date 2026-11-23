// 题意或用途（据代码整理）：多次读入整数，以 0 结束，输出每个非零数含有的最大 2 的幂因子。
// 阅读要点：反复除以 2 直到变奇数，次数 x 对应输出 2^x，也就是通常所说的 lowbit。

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