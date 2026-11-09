#include <bits/stdc++.h>
using namespace std;

int a[1000005][3], n, ans;

 void dfs(int no, int de) {
    ans = max(ans, de);
    if (a[no][1]) {
        dfs(a[no][1], de + 1);
    }
    if (a[no][2]) {
        dfs(a[no][2], de + 1);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2];
    }
    dfs(1, 1);
    cout << ans;
    return 0;
}