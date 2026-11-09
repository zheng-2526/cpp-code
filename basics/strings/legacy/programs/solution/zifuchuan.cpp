#include <bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i += 2) {
        if(s[i] == 'A') a++;
    }
    for(int i = 1; i < s.size(); i += 2) {
        if(s[i] == 'A') b++;
    }
    if((a + b) % 2 == 1) {
        cout << "-1";
        return 0;
    }
    cout << abs(a - b) / 2;
    return 0;
}