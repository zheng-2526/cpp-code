// 题意或用途（据代码整理）：对三列对应的值，计算第三个数减去前两数差的绝对值，将负贡献视为 0，再求和。
// 阅读要点：三次读入分别填表的一列，最后按同一个下标对齐计算。

#include <bits/stdc++.h>
using namespace std;

int n, a[10005][4], ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i][1]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i][2]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i][3]);
    }
    for(int i = 1; i <= n; i++) {
        ans += max(0, a[i][3] - abs(a[i][1] - a[i][2]));
    }
    printf("%d", ans);
    return 0;
}