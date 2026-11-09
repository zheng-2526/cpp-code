#include <bits/stdc++.h>
using namespace std;

int a[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int m, n, x, y, ans;

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < 25; i++) {
        if(a[i] >= m && a[i + 1] <= n) {
            if(ans < a[i + 1] - a[i]) {
                ans = a[i + 1] - a[i];
                x = a[i], y = a[i + 1];
            }
        }
    }
    printf("%d %d %d", x, y, ans);
}