// 题意或用途（据代码整理）：用二分法输出在 1 到 100 内猜中 n 的过程。
// 阅读要点：每次试区间中点，按比较结果排除一半。
// 注意：t 在首次比较之前尚未初始化，仅供阅读二分思路。

#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int t, l = 1, r = 100;
    while(t != n) {
        t = (l + r) / 2;
        printf("%d\n", t);
        if(t > n) r = t - 1;
        else l = t + 1;
    }
    printf("成功！");
    return 0;
}