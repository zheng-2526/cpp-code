#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i < m; i++) {
        cout << i << " 0\n";
    }
    cout << n - m + 1 << " 1";
    return 0;
}