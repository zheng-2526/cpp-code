// 题意或用途（据代码整理）：根据休息时间边界，尝试回答多个时间区间内的休息总长度。
// 阅读要点：应对每段休息区间与询问区间求交，再相加。
// 注意：当前草稿的 if (k = j + 1) 是赋值，且提前退出等边界会影响结果。

#include <bits/stdc++.h>
using namespace std;

int a[200005], n, q, l, r, ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        ans = 0;
        scanf("%d%d", &l, &r);
        for(int j = 2; j <= n; j += 2) {
            if(a[j] >= l) {
                for(int k = j + 1; k <= n; k += 2) {
                    if(a[k] <= r) {
                        if(k = j + 1) ans += a[k] - l;
                        else ans += a[k] - a[k - 1];
                    }
                    else break;
                }
            }
            break;
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}