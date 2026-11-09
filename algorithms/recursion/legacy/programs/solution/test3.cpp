#include <bits/stdc++.h>
using namespace std;

int n;

void hp(int x, char a, char b, char c) {
    if(x == 1) {
        cout << a << "->" << 1 << "->" << c << '\n';
        return;
    }
    hp(x - 1, a, c, b);
    cout << a << "->" << x << "->" << c << '\n';
    hp(x - 1, b, a, c);
}

int main() {
    cin >> n;
    hp(n, 'a', 'b', 'c');
}