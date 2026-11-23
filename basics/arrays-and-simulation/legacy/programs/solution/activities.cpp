// 题意或用途（据代码整理）：统计整数频次，再按奇偶与重复次数进行分段计数，最终输出对半后的结果。
// 阅读要点：a[x] 是值 x 的出现次数，代码只遍历 1..n。原题的配对规则未确认。

#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], maxn, ans;

int main() {
    scanf("%d", &n);
    int x;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1 || a[i] == 3) {
            ans += 1;
            continue;
        }
        if(a[i] % 2 == 1) {
            a[i]--;
            ans++;
        }
        if(a[i] >= 4) {
            while (a[i] >= 4) {
                a[i] -= 2;
                ans += 4;
            }
        }
    }
    cout << ans / 2;
    return 0;
}