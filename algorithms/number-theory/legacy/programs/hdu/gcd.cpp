#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while(T--) {
        int x, maxn = 0;
        scanf("%d", &x);
        for(int i = 1; i <= sqrt(x) && i <= x / 2; i++) {
            if(x % i == 0) maxn = i;
        }
        printf("%d\n", maxn);
    }
}