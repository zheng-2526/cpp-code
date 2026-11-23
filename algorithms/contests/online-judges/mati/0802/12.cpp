// 题意或用途（据代码整理）：从 n 个输入中累加序号为 k 的倍数的元素，序号从 1 开始。
// 阅读要点：边读边求和即可，无需保存整列。取模要求 k 非零。

#include <bits/stdc++.h>
using namespace std;

long long n, k, ans, x;

int main() {
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        if(i % k == 0) ans += x;
    }
    printf("%lld", ans);
}