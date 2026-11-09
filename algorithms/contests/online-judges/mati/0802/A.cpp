#include <bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') a = 1;
        if(s[i] >= 'A' && s[i] <= 'Z') b = 1;
    }
    if(a + b == 1) cout << "Yes";
    else cout << "No";
}