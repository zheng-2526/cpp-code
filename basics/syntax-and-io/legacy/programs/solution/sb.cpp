#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    d /= 4;
    cout << min(a, min(b, min(c, d)));
    return 0;
}