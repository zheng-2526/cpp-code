// 题意或用途（据代码整理）：疑似练习环形连续子段最大和。
// 阅读要点：将原序列再接一遍，前缀和之差代表子段和，可统一处理跨过尾首的区间。
// 注意：现有区间枚举允许结束位置早于开始位置，输出也误传了地址。

#include <bits/stdc++.h>
using namespace std;
#define N 400005

int a[N], b[N], n, ans = -0x3f3f3f;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    for(int i = 1; i <= n; i++) b[i + n] = b[i + n - 1] + a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i + n; j++) {
            ans = max(ans, b[j] - b[i]);
        }
    }
    printf("%d", &ans);
    return 0;
}