#include <bits/stdc++.h>
using namespace std;

int n;
char c;

int main() {
    while(~scanf("%c", &c)) {
        if(c == '6')  {
            n = 0;
            while(1) {
                n++;
                scanf("%c", &c);
                if(c != '6') break;
            }
            if(n <= 3) {
                for(int i = 1; i <= n; i++) printf("6");
            }
            else if(n <= 9) printf("9");
            else printf("27");
            printf("%c", c);
        }
        else printf("%c", c);
    }
    return 0;
}