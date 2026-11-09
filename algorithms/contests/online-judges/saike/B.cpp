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