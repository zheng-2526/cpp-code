#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], maxn, ans;

int main() {
    scanf("%d", &n);
    int x;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1 || a[i] == 3) {
            ans += 1;
            continue;
        }
        if(a[i] % 2 == 1) {
            a[i]--;
            ans++;
        }
        if(a[i] >= 4) {
            while (a[i] >= 4) {
                a[i] -= 2;
                ans += 4;
            }
        }
    }
    cout << ans / 2;
    return 0;
}