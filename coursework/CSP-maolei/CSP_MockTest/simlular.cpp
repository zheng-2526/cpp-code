#include <bits/stdc++.h>
using namespace std;

string s1[10005], s2[10005], s;
map<string, int> mp1, mp2;
int n, m, a, b, t1, t2, ans;

void transfer() {
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        transfer();
        if(mp1[s]++);else s1[++t1] = s;
    }
    for(int i = 1; i <= m; i++) {
        cin >> s;
        transfer();
        if(mp2[s]++);else s2[++t2] = s;
    }
    for(int i = 1; i <= t1; i++) {
        if(mp2[s1[i]]) ans++;
    }
    cout << ans << '\n' << t1 + t2 - ans;
}