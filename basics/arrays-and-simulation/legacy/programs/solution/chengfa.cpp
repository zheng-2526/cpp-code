// 题意或用途（据代码整理）：给两项开头，每次将相邻两项乘积的十进制各位按原顺序附加到数列，输出前 n 项。
// 阅读要点：i 是当前乘积的左下标，x 指向下一处追加位置，按十位、个位的顺序写入。

#include <bits/stdc++.h>
using namespace std;

int a[1005], n;

int main() {
    scanf("%d%d%d", &a[1], &a[2], &n);
    int x = 3;
    for(int i = 1; x <= n + 1; i++) {
        int c = a[i] * a[i + 1];
        if(c < 10) a[x++] = c;
        else {
            a[x++] = c / 10;
            a[x++] = c % 10;
        }
    }
    for(int i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n]);
    return 0;
}