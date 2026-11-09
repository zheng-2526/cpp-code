#include <bits/stdc++.h>
using namespace std;

string s;
int a[210], b, c[210];

int main() {
    cin >> s >> b;
    for(int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }
    int t;
    for(int  i = 0; i < s.size(); i++) {
        t = t * 10 + a[i];
        if(t >= b) {
            c[i] = t / b;
            t = t % b;
        }
        else {
            c[i] = 0;
        }
    }
    int index = 0;
    for(int i = 0; i < s.size(); i++) {
        if(c[i] != 0) {
            index = i;
            break;
        }
    }
    for(int i = index; i < s.size(); i++) {
        printf("%d", c[i]);
    }
    return 0;
}