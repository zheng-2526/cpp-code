#include <bits/stdc++.h>
using namespace std;

int n, a[1005];

void qsort(int l, int r) {
    if(l >= r) return;
    int i = l, j = r, x = a[(l + r) >> 1];
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