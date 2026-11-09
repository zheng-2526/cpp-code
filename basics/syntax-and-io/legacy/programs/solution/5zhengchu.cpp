#include <bits/stdc++.h>
using namespace std;

long long a, b;

int main() {
    cin >> a >> b;
    if(a % 5 == 0 || b % 5 == 0) cout << "Yes";
    else cout << "No";
    return 0;
}