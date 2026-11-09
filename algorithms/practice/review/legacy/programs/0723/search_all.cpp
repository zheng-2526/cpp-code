#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int ans = 1;

int main() {
    cin>>s1 >> s2;
    int len = s1.length();
    for(int i = 0; i < len-1; i++) {
        for(int j = 1; j < len; j++) {
            if(s1[i] == s2[j] && s1[i + 1] == s2[j - 1]) {
                ans *= 2;
            }
        }
    }
    cout<< ans;
    return 0;
}