// 题意或用途（据代码整理）：分别排序左右半段，再合并得到整体升序。
// 阅读要点：合并时双指针比较两段当前最小值，并把剩余尾部抄入缓冲区。相等时这里先取右段。

#include <bits/stdc++.h>
using namespace std;

int a[100005], tmp[100005], n;

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    // 两段分别已排序，每次把两个当前候选中较小的一个放到结果。
    while(i <= mid && j <= r) {
        if(a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(i = l; i <= r; i++) a[i] = tmp[i];
}

void msort(int l, int r) {
    if(l >= r) return;
    int mid = (l + r)  / 2;
    msort(l, mid);
    msort(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    msort(1, n);
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}