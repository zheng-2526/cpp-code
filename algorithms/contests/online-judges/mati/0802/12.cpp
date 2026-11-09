#include <bits/stdc++.h>
using namespace std;

long long n, k, ans, x;

int main() {
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        if(i % k == 0) ans += x;
    }
    printf("%lld", ans);
}