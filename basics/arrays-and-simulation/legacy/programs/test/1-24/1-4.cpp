// 题意或用途（据代码整理）：根据四个轮胎的读数、最低允许值和最大允许偏差，报告单胎或多胎异常。
// 阅读要点：低于阈值或落后最大读数太多时记异常。
// 注意：旧实现求最大值时连后两个阈值也参与比较，需要按照题面核对。

#include <bits/stdc++.h>
using namespace std;

int a[10], maxn, ans;

int main() {
    for(int i = 1; i <= 6; i++) {
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
    }
    for(int i = 1; i <= 4; i++) {
        if((maxn - a[i] > a[6]) || (a[i] < a[5])) {
            // printf("%d", a[i]);
            if(ans) {
                printf("Warning: please check all the tires!");
                return 0;
            }
            ans = i;
        }
    }
    if(ans) printf("Warning: please check #%d!", ans);
    else printf("Normal");
    return 0;
}