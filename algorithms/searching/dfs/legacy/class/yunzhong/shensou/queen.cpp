#include <bits/stdc++.h>
using namespace std;

bool l[15], z[30], f[30];
int num[15], ans, n;

void queen(int x) {
    if(x == n + 1) {
        ans++;
        if(ans <= 3) {
            for(int i = 1; i <= n; i++) {
                cout << num[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!l[i] && !z[x - i + n] && !f[x + i]) {
            l[i] = z[x - i + n] = f[x + i] = true;
            num[x] = i;
            queen(x + 1);
            l[i] = z[x - i + n] = f[x + i] = false;
        }
    }
}

int main() {
    cin >> n;
    queen(1);
    cout << ans;
    return 0;
}