#include <bits/stdc++.h>
using namespace std;

int n, num[10];
bool a[10];

void A(int t) {
    if(t == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!a[i]) {
            a[i] = true;
            num[t] = i;
            A(t + 1);
            a[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    A(1);
    return 0;
}