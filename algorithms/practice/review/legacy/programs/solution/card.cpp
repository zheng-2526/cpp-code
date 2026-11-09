#include <bits/stdc++.h>
using namespace std;

int n, a[105], ans1, ans2;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(n % 2 == i % 2) {
            ans1 += a[i];
        }
        else {
            ans2 += a[i];
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}