#include <bits/stdc++.h>
using namespace std;

int a[10], maxn, ans;

int main() {
    for(int i = 1; i <= 6; i++) {
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
    }
    for(int i = 1; i <= 4; i++) {
        if((maxn - a[i] > a[6]) || (a[i] < a[5])) {
            // printf("%d", a[i]);
            if(ans) {
                printf("Warning: please check all the tires!");
                return 0;
            }
            ans = i;
        }
    }
    if(ans) printf("Warning: please check #%d!", ans);
    else printf("Normal");
    return 0;
}