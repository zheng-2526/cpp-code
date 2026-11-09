#include <bits/stdc++.h>
using namespace std;

long long t, n;

int main() {
    scanf("%lld", &t);
    while(t--) {
        long long ans = 0;
        scanf("%lld", &n);
        if(n & 1) ans = n * (n - 1) / 2;
        else ans = n * (n - 2) / 2;
        if(n % 3 == 0) ans -= n / 3 * 2;
        printf("%lld\n", ans);
    }
}