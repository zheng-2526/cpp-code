#include <bits/stdc++.h>
using namespace std;

string s[51], tmp;
bool a[51];
int n, ans;

void dfs(int r) {
    bool flag = false;
    string tmp2;
    for(int i = 1; i <= n; i++) {
        if(a[i]) continue;
        if(tmp[1] != s[i][0]) continue;
        flag = true;
        a[i] = true;
        tmp2 = tmp;
        tmp = s[i];
        dfs(r + 1);
        tmp = tmp2;
        a[i] = false;
    }
    if(!flag) ans = max(ans, r - 1);
}

int main() {
    cin >> n;
    getchar();
    for(int i = 1; i <= n; i++) {
        getline(cin, s[i]);
    }
    tmp = s[1];
    a[1] = true;
    dfs(2);
    cout << ans;
    return 0;
}