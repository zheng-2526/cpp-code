// 题意或用途（据代码整理）：尝试统计数组中差值为 c 的数对。
// 阅读要点：先排序，想找与 a[i]-c 相等的那段连续位置。
// 注意：现有 while 的 continue 分支不移动 l，会卡住；这里保留作待改进练习。

#include <bits/stdc++.h>
using namespace std;

int n, c, a[200005], ans, l, r;

int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        l = r + 1, r = l;
        while(l <= i) {
            if(a[l] + c < a[i]) continue;
            else {
                for(r = l; r <= i; r++) {
                    if(a[r] + c > a[i]) {
                        break;
                    }
                }
                break;
            }
        }
        ans += (r - l);
    }
    printf("%d\n", ans);
    return 0;
}