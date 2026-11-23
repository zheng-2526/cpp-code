// 题意或用途（据代码整理）：给定初始阈值，分轮输出达到条件的元素下标，并用剩余元素的平均值更新阈值。
// 阅读要点：数组第二列记录已输出，两个扫法对应不同方向。
// 注意：轮次变量 x 未在循环中更新，实际不会交替换方向。

#include <bits/stdc++.h>
using namespace std;

int n, a[1005][3], t, cnt, ans, x;

int main() {
    scanf("%d%d", &n, &t);
    for(int i = 1; i <= n; i++) {
        cin >> a[i][1];
        if(a[i][1] <= t) {
            printf("%d", i);
            a[i][2] = 1;
            cnt++;
            if(cnt < n) printf(" ");
        }
        else ans += a[i][1];
    }
    x++;
    if(cnt == n) return 0;
    t = ans / (n - cnt);
    ans = 0;
    while(cnt < n) {
        if(x % 2 == 0) {
            for(int i = 1; i <= n; i++) {
                if(a[i][1] <= t) {
                    if(a[i][2] == 0) {
                        printf("%d", i);
                        a[i][2] = 1;
                        cnt++;
                        if(cnt < n) printf(" ");
                    }
                }
                else ans += a[i][1];
            }
            if(cnt == n) return 0;
            t = ans / (n - cnt);
        }
        else {
            for(int i = n; i >= 1; i--) {
                if(a[i][1] <= t) {
                    if(a[i][2] == 0) {
                        printf("%d", i);
                        a[i][2] = 1;
                        cnt++;
                        if(cnt < n) printf(" ");
                    }
                }
                else ans += a[i][1];
            }
            if(cnt == n) return 0;
            t = ans / (n - cnt);
        }
        ans = 0;
    }
}