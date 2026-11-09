#include<bits/stdc++.h>
using namespace std;

long long x, a;

int main() {
    cin >> x;
    if(x < 0) {
        cout << '-';
        x = -x;
    }
    while(x != 0) {
        a *= 10;
        a += x % 10;
        x /= 10;
    }
    cout << a;
    return 0;
}