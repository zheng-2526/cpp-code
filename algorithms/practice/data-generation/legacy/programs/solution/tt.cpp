#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("zyz.in", "w", stdout);
    cout << 100000 << ' ' << 100000 << '\n';
    for(int i = 1; i <= 100000; i++) {
        cout << i % 100 + 1 << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= 100000; i++) cout << 100000 << ' ' << 100000 << '\n';
}