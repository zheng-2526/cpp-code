#include <bits/stdc++.h>
using namespace std;

int n, minn = 0x3f3f3f, minnum, maxn = -1, maxnum, x;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x > maxn) {
            maxn = x;
            maxnum = 1;
        }
        else if(x == maxn) maxnum++;
        if(x <minn) {
            minnum = 1;
            minn = x;
        }
        else if(x == minn) minnum++;
    }
    printf("%d %d\n%d %d", minn, minnum, maxn, maxnum);
    return 0;
}