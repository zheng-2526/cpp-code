// 题意或用途（据代码整理）：读取序列直到首次遇到 1，输出它之前的元素数及 0 的个数。
// 阅读要点：扫描时只对 0 累加，遇到 1 立即结束。整段无 1 时现有代码没有输出。

#include <bits/stdc++.h>
using namespace std;

int n, x, t;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if(t == 0) {
            x++;
            continue;
        }
        if(t == 1) {
            cout << i - 1 << ' ' << x;
            return 0;
        }
    }
}