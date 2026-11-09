#include <bits/stdc++.h>
using namespace std;

int T, x1, x2, yy1, yy2;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &x1, &yy1, &x2, &yy2);
        if(x1 == 1 && x2 == 2 && yy1 == yy2) {
            printf("YES\n");
            continue;
        }
        if(yy1 == 1 && yy2 == 2 && x1 == x2) {
            printf("YES\n");
            continue;
        }
        if(x1 == 9 && x2 == 8 && yy1 == yy2) {
            printf("YES\n");
            continue;
        }
        if(yy1 == 10 && yy2 == 9 && x1 == x2) {
            printf("YES\n");
            continue;
        }
        if(x1 == 1 && yy1 == 1) {
            if(x2 == 2 && yy2 == 2 || x2 == 3 && yy2 == 3 || x2 == 1 && yy2 == 2 || x2 == 2 && yy2 == 1) {
                printf("yes\n");
                continue;
            }
        }
        if(x1 == 9 && yy1 == 10) {
            if(x2 == 8 && yy2 == 9 || x2 == 7 && yy2 == 8 || x2 == 9 && yy2 == 9 || x2 == 8 && yy2 == 10) {
                printf("yes\n");
                continue;
            }
        }
        if(x1 == 1 && yy1 == 10) {
            if(x2 == 2 && yy2 == 9 || x2 == 3 && yy2 == 8 || x2 == 1 && yy2 == 9 || x2 == 2 && yy2 == 10) {
                printf("yes\n");
                continue;
            }
        }
        if(x1 == 9 && yy1 == 1) {
            if(x2 == 8 && yy2 == 2 || x2 == 7 && yy2 == 2 || x2 == 8 && yy2 == 1 || x2 == 9 && yy2 == 2) {
                printf("yes\n");
                continue;
            }
        }
        printf("NO\n");
    }
    return 0;
}