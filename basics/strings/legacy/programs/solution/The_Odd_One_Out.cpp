#include <bits/stdc++.h>
using namespace std;

string s;
int a[27];
bool flag;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) a[s[i] - 'a' + 1]++;
    for(int i = 1; i <= 26; i++) if(a[i] == 1) printf("%c", i + 'a' - 1);
    return 0;
}