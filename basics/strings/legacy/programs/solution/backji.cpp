#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
string s[31];
bool a[31];

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 1; i <= n; i++) {
        getline(cin, s[i]);
        if(s[i].find("qiandao") != string::npos || s[i].find("easy") != string::npos)
            a[i] = 1;
    }
    // for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    for(int i = 1; i <= n; i++) {
        if(a[i]) continue;
        ans++;
        if(ans == m + 1) {
            cout << s[i];
            return 0;
        }
    }
    cout << "Wo AK le";
    return 0;
}