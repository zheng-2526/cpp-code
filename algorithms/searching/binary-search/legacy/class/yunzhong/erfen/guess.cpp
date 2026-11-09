#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int t, l = 1, r = 100;
    while(t != n) {
        t = (l + r) / 2;
        printf("%d\n", t);
        if(t > n) r = t - 1;
        else l = t + 1;
    }
    printf("成功！");
    return 0;
}