// 题意或用途（据代码整理）：将数组按下标奇偶分为两组，各自求和，先输出和 n 奇偶相同的一组。
// 阅读要点：使用一基下标，在读入时即可确定分组。

#include <bits/stdc++.h>
using namespace std;

int n, a[105], ans1, ans2;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(n % 2 == i % 2) {
            ans1 += a[i];
        }
        else {
            ans2 += a[i];
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}