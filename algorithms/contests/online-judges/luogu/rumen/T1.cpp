#include <bits/stdc++.h>
using namespace std;

int x, a, b, t;

int main() {
    cin >> x >> a >> b >> t;
    if(x < 60) {
        cout << 0;
        return 0;
    }
    if(x >= 60 && x < 120) {
        cout << a;
        return 0;
    }
    if(x >= 120 && x < 240) {
        cout << b;
        return 0;
    }
    if(x >= 240) {
        cout << t;
        return 0;
    }
}