// 题意或用途（据代码整理）：输入 n 个数，输出最小值、最大值及它们各自的出现次数。
// 阅读要点：遇到新极值重置计数，同值则累加。哨兵初值假定输入落在相应范围。

#include <bits/stdc++.h>
using namespace std;

int n, minn = 0x3f3f3f, minnum, maxn = -1, maxnum, x;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x > maxn) {
            maxn = x;
            maxnum = 1;
        }
        else if(x == maxn) maxnum++;
        if(x <minn) {
            minnum = 1;
            minn = x;
        }
        else if(x == minn) minnum++;
    }
    printf("%d %d\n%d %d", minn, minnum, maxn, maxnum);
    return 0;
}