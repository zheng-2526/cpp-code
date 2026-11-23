// 题意或用途（据代码整理）：用双指针快速排序将整数序列升序排列。
// 阅读要点：选中间元素为基准，左右找放错侧的元素并交换，再递归剩余两段。

#include <bits/stdc++.h>
using namespace std;

int n, a[1005];

void qsort(int l, int r) {
    if(l >= r) return;
    int i = l, j = r, x = a[(l + r) >> 1];
    // i、j 之间是尚未分区的部分，交换后缩小它。
    while(i <= j) {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) qsort(l, j);
    if(i < r) qsort(i, r);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    qsort(1, n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    return 0;
}