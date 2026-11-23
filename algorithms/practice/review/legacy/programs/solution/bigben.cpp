// 题意或用途（据代码整理）：读取 0 至 23 点的 24 个数，查询某小时的数值并判断是否大于 50。
// 阅读要点：越界小时作为结束标记，数组可直接按小时索引。
// 注意：现有 Yes 分支缺少换行，也没有检查读入是否已结束。

#include <bits/stdc++.h>
using namespace std;

int a[24], x;

int main() {
    for(int i = 0; i <= 23; i++) {
        scanf("%d", &a[i]);
    }
    while(1) {
        scanf("%d", &x);
        if(x < 0 || x > 23) break;
        if(a[x] > 50) printf("%d Yes", a[x]);
        else printf("%d No\n", a[x]);
    }
    return 0;
}