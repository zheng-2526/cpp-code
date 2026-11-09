#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int a1[210], a2[210], ans[210];

int main() {
    getline(cin, s1);
    getline(cin, s2);
    int t = 0;
    for(int i = s1.size() - 1; i >= 0; i--) {
        a1[i] = s1[t++] - '0';
    }
    t = 0;
    for(int i = s2.size() - 1; i >= 0; i--) {
        a2[i] = s2[t++] - '0';
    }
    for(int i = 0; i <= max(s1.size(), s2.size()); i++) {
        ans[i] = a1[i] + a2[i] + ans[i - 1] / 10;
        if(ans[i - 1] >= 10) ans[i - 1] %= 10;
    }
    if(ans[max(s1.size(), s2.size())] >= 1) {
        for(int i = max(s1.size(), s2.size()); i >= 0; i--) {
            cout << ans[i];
        }
    } else {
        for(int i = max(s1.size(), s2.size()) - 1; i >= 0; i--) {
            cout << ans[i];
        }
    }
    return 0;
}