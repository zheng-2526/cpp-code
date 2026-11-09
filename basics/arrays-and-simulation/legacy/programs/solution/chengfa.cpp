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