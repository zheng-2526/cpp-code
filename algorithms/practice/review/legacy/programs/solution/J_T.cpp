// 题意或用途（据代码整理）：读入整数列，用长度以及最小值首次出现位置的奇偶判 Tom/Jerry 胜负。
// 阅读要点：遍历时仅在严格更小的值出现时更新下标，故多个最小值取最左，且下标从 0 开始。

#include <bits/stdc++.h>
using namespace std;

int T, a[1005], n;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int minn = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if(n % 2) {
            printf("Jerry\n");
            continue;
        }
        for(int i = 0; i < n; i++) {
            minn = a[i] < a[minn] ? i : minn;
            // if(a[i] < a[minn]) minn = i;
        }
        if(minn % 2) {
            printf("Jerry\n");
        } else {
            printf("Tom\n");
        }
    }
    return 0;
}