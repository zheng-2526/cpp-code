#include <bits/stdc++.h>
using namespace std;

char s[1005][1005];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << s[i] << endl;
    }
}