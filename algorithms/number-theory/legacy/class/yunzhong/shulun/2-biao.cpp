// 题意或用途（据代码整理）：用位数组从 0 开始逐次加一，逐行展示 32 位二进制计数。
// 阅读要点：从最低位进位，遇到 0 变 1 后停止，原先连续的 1 全改成 0。

#include <bits/stdc++.h>
using namespace std;
 
int x, a[33];
 
int main() {
    scanf("%d", &x);
    for(int i = 1; i <= x; i++) {
        for(int i = 1; ; i++) {
            if(a[i] == 0) {
                a[i] = !a[i];
                break;
            }
            a[i] = !a[i];
        }
        for(int i = 32; i >= 1; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}