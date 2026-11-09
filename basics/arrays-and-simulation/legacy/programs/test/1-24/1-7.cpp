#include <bits/stdc++.h>
using namespace std;

int n, m, x[35], ans;
char c;

int main() {
    scanf("%d %d", &n, &m);
    while(m--) {
        ans = 0;
        getchar();
        for(int i = 1; i <= n; i++) {
            c = getchar();
            if(c == 'n') x[i] = 1;
            else x[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            // printf("%d ", n - i);
            ans += x[i] * pow(2, n - i);
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}