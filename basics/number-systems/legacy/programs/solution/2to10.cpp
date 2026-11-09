#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char c;

int main() {
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; i++) {
        c = getchar();
        ans = ans * 2 + (c - '0');
    }
    printf("%d\n", ans);
    return 0;
}