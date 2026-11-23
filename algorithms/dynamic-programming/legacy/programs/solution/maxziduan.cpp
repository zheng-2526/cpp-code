// 题意或用途（据代码整理）：给定整数数组，求非空连续子段的最大和。
// 阅读要点：ad[i] 是以 i 结尾的最佳子段。若上一段和为负，直接从 a[i] 重新开始，再在所有结尾中取最大值。

#include <bits/stdc++.h>
using namespace std;

int a[10005], n, ad[10005], ans = -0x3f3f3f3f;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        // 负和前缀只会拖低当前结果，此时重新从 a[i] 开始。
        ad [i - 1] < 0 ? ad[i] = a[i] : ad[i] = ad[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        ans = max(ans, ad[i]);
        // printf("%d ", ad[i]);
    }
    printf("%d", ans);
    return 0;
}