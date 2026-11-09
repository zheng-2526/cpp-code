#include <bits/stdc++.h>
using namespace std;

int a[1005], T, n;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++) {
            flag = true;
            for(int j = i; j <= i + n - 1; j++) {
                if(j == n) {
                    if(a[j] > a[1]) {
                        flag = 0;
                        break;
                    }
                }
                else if(j > n) {
                    if(a[j - n] > a[j + 1 - n]) {
                        flag = 0;
                        break;
                    }
                }
                else {
                    if(a[j] > a[j + 1]) {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}