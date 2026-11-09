#include <bits/stdc++.h>
using namespace std;

int a[24], x;

int main() {
    for(int i = 0; i <= 23; i++) {
        scanf("%d", &a[i]);
    }
    while(1) {
        scanf("%d", &x);
        if(x < 0 || x > 23) break;
        if(a[x] > 50) printf("%d Yes", a[x]);
        else printf("%d No\n", a[x]);
    }
    return 0;
}