#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d ", &n);
    while(n--) {
        char c;
        int x;
        scanf("%c %d ", &c, &x);
        if(c == 'r') {
            c = getchar();
            for(int i = 1; i <= x; i++) {
                if(!(c >= '0' && c <= '9')) {
                    printf("%c", c);
                }
                c = getchar();
            }
            printf("\n");
        }
        else if(c == 'c') {
            c = getchar();
            for(int i = 1; i <= x; i++) {
                if(!(c >= 'A' && c <= 'Z')) {
                    printf("%c", c);
                }
                else printf("%c", c + 32);
                c = getchar();
            }
            printf("\n");
        }
        else if(c == 'C') {
            c = getchar();
            for(int i = 1; i <= x; i++) {
                if(!(c >= 'a' && c <= 'z')) {
                    printf("%c", c);
                }
                else printf("%c", c - 32);
                c = getchar();
            }
            printf("\n");
        }
    }
    return 0;
}