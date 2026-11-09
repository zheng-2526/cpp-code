#include<bits/stdc++.h> 
using namespace std;

const int mod = 1e9 +7;
int n, d, ans[1005];

int main() {
    ans[0] = 1;
    cin >> n >> d;
    if(d == 1) {
        for(int i = 1; i <= n; i++) ans[i] = ans[i - 1] * 4 % mod;
        cout << ans[n];
        return 0;
    }
    for(int i = 1; i < d; i++) ans[i] = i * 2 + 1;
    for(int i = d; i <= n; i++) ans[i] = 2 + ans[i - 1] + ans[i - d ]
    return 0;
}