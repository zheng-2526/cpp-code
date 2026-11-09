#include <bits/stdc++.h>
using namespace std;

long long n, d, x[100005], v[100005], a, r, ans;

int main() {
    cin >> n >> d;
    for(int i = 1; i < n; i++) {
        cin >> x[i];
    }
    cin >> v[1];
    for(int i = 2; i <= n; i++) {
        cin >> a;
        v[i] = a > v[i - 1] ? v[i - 1] : a;
    }
    for(int i = 1; i < n; i++) {
        int xx = ceil(1.0 * (x[i] - r) / d);
        ans += xx * v[i];
        r = xx * d - (x[i] - r);
    }
    cout << ans;
}