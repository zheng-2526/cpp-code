// 题意或用途（据代码整理）：疑似经典过桥问题：每人有过桥用时，两人同行按较慢者计时，设计最短总用时方案。
// 阅读要点：先排序，每轮比较运送两个最慢者的两种往返策略；剩两人或三人时直接计算。
// 注意：原版本没为单人补上用时。

#include <bits/stdc++.h>
using namespace std;

int i, n, a[100010];
long long ans;

bool cmp(const int x, const int y) {
    return x < y;
}

int main() {
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);//按用时由小到大排序
    while(n > 3) {
        ans += min(a[1] * 2 + a[n] + a[n-1], a[1] + a[2] * 2 + a[n]);//根据公式累加
        n -= 2;//每次此岸人数减少2人
    }
    if(n == 2) ans += a[2];//此岸人数n为2或3时
    if(n == 3) ans += a[1] + a[2] + a[3];
    printf("%lld", ans);
    return 0;
}