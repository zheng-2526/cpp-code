#include <bits/stdc++.h>
using namespace std;

int n, k, T, ans, maxn;
char s[500005];

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> k;
        maxn = 0;
        getchar();
        memset(s, 0, sizeof(s));
        if(k > 4) k = 4;
        for(int i = 1; i <= n; i++) cin >> s[i];
        for(int i = 1 ; i <= 4; i++) s[n + i] = s[i];
        for(int kk = 0; kk <= k; kk++) {
            ans = 0;
            for(int i = 1 + kk; i <= n + kk - 3; i++) {
                if(s[i] == 'c') {
                    if(s[i + 1] == 'u' && s[i + 2] == 'm' && s[i + 3] == 't') ans++;
                }
            }
            maxn = max(maxn, ans);
        }
        cout << maxn << '\n';
    }
    return 0;
}