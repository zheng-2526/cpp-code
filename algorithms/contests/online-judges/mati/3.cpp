#include<bits/stdc++.h> 
using namespace std;

int n, m, t1, t2, g[1002][1002], ans;

int main() {
    cin >> n >> m >> t1 >> t2;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    int a = n / t1, b = m / t2;
    int num = a * b;
    for(int k = 1; k <= num; k++) {
        int xx = 0;
        for(int  i = (k - 1) / b * t1 + 1; i <= (k - 1) / b * t1 + t1; i++) {
            for(int j = (k - 1) % b * t2 + 1; j <= (k - 1) % b * t2 + t2; j++) {
                xx ^= g[i][j];
            }
        }
        ans += xx;
        // cout << xx << '\n';
    }
    cout << ans;
    return 0;
}