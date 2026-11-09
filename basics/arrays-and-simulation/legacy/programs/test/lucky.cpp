#include <bits/stdc++.h>
using namespace std;

int T, n, ans1, ans2;

int main() {
    scanf("%d", &T);
    while(T--) {
        ans1 = ans2 = 0;
        scanf("%d", &n);
        for(int i = 1; i <= 3; i++) {
            ans1 += (n % 10);
            n /= 10;
        }
        for(int i = 1; i <= 3; i++) {
            ans2 += (n % 10);
            n /= 10;
        }
        if(ans1 == ans2) printf("You are lucky!\n");
        else printf("Wish you good luck.\n");
    }
    return 0;
}