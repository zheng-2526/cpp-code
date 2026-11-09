#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sch(LL a, LL b, LL c) {
    LL res = 0;
    while(b) {
        if(b & 1) res = (res + a) % c;
        a = a * 2 % c;
        b >>= 1;
    }
    return res;
}

int main() {
    LL a, b, c;
    cin >> a >> b >> c;
    cout << sch(a, b, c) << endl;
    return 0;
}