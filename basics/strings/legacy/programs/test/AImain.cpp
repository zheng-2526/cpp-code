#include <bits/stdc++.h>
using namespace std;

string s, l[1005];
int N, n;

int main() {
    scanf("%d\n", &N);
    while(N--) {
        getline(cin, s);
        cout << s << '\n';
        cout << "AI: ";
        if(s[0] == ' ') n = 0;
        else n = 1;
        l[1] = "";
        for(int i = 0; i < s.size(); i++) {
            while(s[i] == ' ') i++;
            if(s[i - 1] == ' ') {
                n++;
                l[n] = "";
            }
            if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'I') s[i] += 32;
            if(s[i] == '?') s[i] = '!';
            l[n] += s[i];
        }
        for(int i = 1; i <= n; i++) {
            if(i != 1 && (l[i][0] == 'I' || l[i][0] >= '0' && l[i][0] <= '9' || l[i][0] >= 'a' && l[i][0] <= 'z')) printf(" ");
            if(l[i] == "I" || l[i] == "me") {
                cout << "you";
                continue;
            }
            if(l[i] == "can" && l[i + 1] == "you") {
                cout << "I can";
                i++;
                continue;
            }
            if(l[i] == "could" && l[i + 1] == "you") {
                cout << "I could";
                i++;
                continue;
            }
            cout << l[i];
        }
        // for(int i = 1; i <= n; i++) {
        //     cout << l[i] << ' ';
        // }
        cout << '\n';
    }
    return 0;
}