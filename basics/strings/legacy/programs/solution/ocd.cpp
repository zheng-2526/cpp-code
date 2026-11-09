#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);
    if(s.size() == 4) {
        if(s[0] > '2') {
            printf("19%c%c-%c%c", s[0], s[1], s[2], s[3]);
            return 0;
        }
        if(s[0] == '2') {
            if(s[1] < '2') printf("20%c%c-%c%c", s[0], s[1], s[2], s[3]);
            else printf("19%c%c-%c%c", s[0], s[1], s[2], s[3]);
            return 0;
        }
        printf("20%c%c-%c%c", s[0], s[1], s[2], s[3]);
        return 0;
    }
    else printf("%c%c%c%c-%c%c", s[0], s[1], s[2], s[3], s[4], s[5]);
    return 0;
}