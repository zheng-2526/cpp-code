// 题意或用途（据代码整理）：读入 n、m、k，输出从 n 中扣去 m*k 的剩余量。
// 阅读要点：先按乘法求总扣除量，再做减法。原题的计量单位未确认。

#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    printf("%d", n - (m * k));
    return 0;
}