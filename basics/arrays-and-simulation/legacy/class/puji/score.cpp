#include <bits/stdc++.h>
using namespace std;
 
int n, a[25][25];
 
int main() {
    scanf("%d", &n);
    int i = 1, count = 1;
    while(i <= (n + 1) / 2) {
        for(int j = i; j <= n - i + 1; j++) {
            a[j][n - i + 1] = count;
            count++;
        }
        for(int j = n - i; j >= i; j--) {
            a[n - i + 1][j] = count;
            count++;
        }
        for(int j = n - i; j >= i; j--) {
            a[j][i] = count;
            count++;
        }
        for(int j = i + 1; j <= n - i; j++) {
            a[i][j] = count;
            count++;
        }
        i++;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}