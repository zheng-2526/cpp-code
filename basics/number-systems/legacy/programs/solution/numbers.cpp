#include <bits/stdc++.h>
using namespace std;

int x, a[33];

int main() {
    scanf("%d", &x);
    for(int i = 1; i <= x; i++) {
        for(int i = 1; ; i++) {
            if(a[i] == 0) {
                a[i] = !a[i];
                break;
            }
            a[i] = !a[i];
        }
        for(int i = 32; i >= 1; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}