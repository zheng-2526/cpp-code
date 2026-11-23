// 题意或用途（据代码整理）：对每个 x 枚举不超过 sqrt(x) 且不超过 x/2 的因子，输出其中最大者。
// 阅读要点：x % i 为 0 表示 i 是因子。文件名虽为 gcd，程序的实际输入不是两个数。

#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while(T--) {
        int x, maxn = 0;
        scanf("%d", &x);
        for(int i = 1; i <= sqrt(x) && i <= x / 2; i++) {
            if(x % i == 0) maxn = i;
        }
        printf("%d\n", maxn);
    }
}