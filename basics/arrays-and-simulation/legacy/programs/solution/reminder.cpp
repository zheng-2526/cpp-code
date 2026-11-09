#include <bits/stdc++.h>
using namespace std;

int n, m;
double x;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &x);
        if(x < m) printf("On Sale! %.1lf\n", x);
    }
    return 0;
}