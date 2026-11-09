#include <bits/stdc++.h>
using namespace std;

int a, b, ans[10005], ls;

int main() {
    scanf("%d%d", &a, &b);
    printf("%d=", a);
    while(a != 0) {
        ans[++ls] = a % b;
        a /= b;
        if(ans[ls] < 0) {
            ans[ls] -= b;
            a++;
        }
    }
    for(int i = ls; i > 0; i--) {
        if(ans[i] < 10) printf("%d", ans[i]);
        else printf("%c", ans[i] - 10 + 'A');
    }
    printf("(base%d)", b);
    return 0;
}