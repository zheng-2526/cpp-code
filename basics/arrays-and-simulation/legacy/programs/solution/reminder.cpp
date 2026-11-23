// 题意或用途（据代码整理）：给定售价阈值，筛出严格小于阈值的商品报价并保留一位小数。
// 阅读要点：边读边判断，相等时不打印。

#include <bits/stdc++.h>
using namespace std;

int n, m;
double x;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &x);
        if(x < m) printf("On Sale! %.1lf\n", x);
    }
    return 0;
}