// 题意或用途（据代码整理）：判断数组是否能通过循环旋转变成非降顺序。
// 阅读要点：逐个枚举起点并检查相邻项。
// 注意：现有循环也比较了旋转末项与首项，可能把本来合法的旋转判错。

#include <bits/stdc++.h>
using namespace std;

int a[1005], T, n;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++) {
            flag = true;
            for(int j = i; j <= i + n - 1; j++) {
                if(j == n) {
                    if(a[j] > a[1]) {
                        flag = 0;
                        break;
                    }
                }
                else if(j > n) {
                    if(a[j - n] > a[j + 1 - n]) {
                        flag = 0;
                        break;
                    }
                }
                else {
                    if(a[j] > a[j + 1]) {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}