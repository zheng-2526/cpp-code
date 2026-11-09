#include <bits/stdc++.h>
using namespace std;

char a, b;
int c;

int main() {
    cin >> a >> b >> c;
    if(a == 'A') {
        if(b == 'N') cout << "A320";
        else {
            if(c == 2) cout << "A350";
            else cout << "A380";
        }
        return 0;
    }
    else if(a == 'B') {
        if(b == 'N') cout << "B737";
        else {
            if(c == 2) cout << "B787";
            else cout << "B747";
        }
        return 0;
    }
    else cout << "C919";
    return 0;
}