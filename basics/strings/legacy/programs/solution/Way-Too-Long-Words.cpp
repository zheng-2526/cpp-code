#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
    scanf("%d", &n);
    getchar();
    while(n--) {
        getline(cin, s);
        if(s.size() > 10)
            printf("%c%d%c\n", s[0], s.size() - 2, s[s.size() - 1]);
        else cout << s << '\n';
    }
    return 0;
}