// 题意或用途（据代码整理）：从 n 递归拆分：当 x 大于 k 且 x-k 为偶数时，把 x 拆成差为 k 的两个正整数。
// 阅读要点：每次把一段换成两段，最终段数净增 1，所以 ans 从 1 开始，每拆一次加 1。

#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 1;

void dfs(int x) {
    if(x <= k) return;
    if((x - k) % 2 == 0) {
        ans++;
        dfs((x - k) >> 1);
        dfs(((x - k) >> 1) + k);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    dfs(n);
    printf("%d", ans);
    return 0;
}