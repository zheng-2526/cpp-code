// 题意或用途（据代码整理）：判断给定整数是否为质数。
// 阅读要点：小于 2 直接排除，只需试除到平方根：合数的因子对至少有一项不超过平方根。

#include <bits/stdc++.h>
using namespace std;

long long a;

bool isZhishu(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> a;
    printf("%s\n", isZhishu(a) ? "YES" : "NO");
}