// 题意或用途（据代码整理）：把两个数组的元素一一配对，求 a 严格大于 b 的最大匹配数。
// 阅读要点：两边排序，当前最小 a 若无法战胜最小 b，则它也无法战胜后面的 b，可丢弃；否则立即配成一对。

#include<bits/stdc++.h>
using namespace std;

int a[50004], b[50004], n, ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int i = 1, j = 1;
    while(i <= n && j <= n) {
        if(a[i] <= b[j]) {
            i++;
        }
        else {
            i++;
            j++;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}