#include <bits/stdc++.h>
using namespace std;
 
long long n, T;
 
int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n & 1) printf("No\n");
        else printf("Yes\n%lld %lld\n", n / 2, n / 2);
    }
    return 0;
}