#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    freopen("zyz1.in", "r", stdin);
    cin >> x >> y;
    cout << ((x == y) ? (x + 1) : (min(x, y) + 2));
    return 0;
}