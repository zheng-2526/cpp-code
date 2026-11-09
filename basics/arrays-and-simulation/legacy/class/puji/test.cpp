#include <bits/stdc++.h>
using namespace std;

int x, n, a, b, ans;

int main() {
    cin >> n;
    while(n--) {
        cin >> a >> b;
        x = x + a - b;
        ans = max(ans, x);
    }
    cout << ans;
    return 0;
}