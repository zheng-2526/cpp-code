// 题意或用途（据代码整理）：用快速排序按升序排列序列。
// 阅读要点：i 与 j 相向扫描，交换两侧不符合基准关系的数，分区后只处理仍未排序的范围。

#include <bits/stdc++.h>
using namespace std;

int a[100005], n;

void qsort(int l, int r) {
    if(l > r) return;
    int mid = (l + r) / 2;
    int i = l, j = r, p = a[mid];
    while(i <= j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) qsort(l, j);
    if(i < r) qsort(i, r);
    return;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    qsort(1, n);
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}