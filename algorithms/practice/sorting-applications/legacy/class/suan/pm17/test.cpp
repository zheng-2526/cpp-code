#include<bits/stdc++.h>
using namespace std;

int a[50004], b[50004], n, ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int i = 1, j = 1;
    while(i <= n && j <= n) {
        if(a[i] <= b[j]) {
            i++;
        }
        else {
            i++;
            j++;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}