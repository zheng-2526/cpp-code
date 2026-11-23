// 题意或用途（据代码整理）：程序按 n 与 x 的大小，输出从 1 到 floor(x/2) 的一段整数，符合分支时再输出 [x,n]。
// 阅读要点：先算输出个数，再按两个区间打印。原题要求构造的性质未能确认。

#include <bits/stdc++.h>
using namespace std;

int n, x, a[300005], t, ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &x);
        if(n >= x) {
            ans = n + 1 - (x + 1) / 2;
            printf("%d\n", ans);
            for(int i = 1; i <= x / 2; i++) printf("%d ", i);
            for(int i = x; i <= n; i++) printf("%d ", i);
            printf("\n");
        }
        else {
            ans = x / 2;
            printf("%d\n", ans);
            for(int i = 1; i <= x / 2; i++) printf("%d ", i);
            printf("\n");
        }
    }
}