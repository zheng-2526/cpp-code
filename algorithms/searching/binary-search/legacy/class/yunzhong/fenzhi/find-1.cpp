#include <bits/stdc++.h>
using namespace std;

int a[10005], n, x;

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m] == x) {
            cout << m;
            return 0;
        }
        if(x < a[m]) r = m - 1;
        else l = m + 1;
    }
    cout << -1;
    return 0;
}