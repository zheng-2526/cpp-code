#include <bits/stdc++.h>
using namespace std;

int T, a[1005], n;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int minn = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if(n % 2) {
            printf("Jerry\n");
            continue;
        }
        for(int i = 0; i < n; i++) {
            minn = a[i] < a[minn] ? i : minn;
            // if(a[i] < a[minn]) minn = i;
        }
        if(minn % 2) {
            printf("Jerry\n");
        } else {
            printf("Tom\n");
        }
    }
    return 0;
}