#include <bits/stdc++.h>
using namespace std;

int a;

int main() {
    while(1) {
        scanf("%d", &a);
        if(a == 0) break;
        int x = 0;
        while(!(a % 2)) {
            a /= 2;
            x++;
        }
        printf("%d\n", (1 << x));
    }
    return 0;
}