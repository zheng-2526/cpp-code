#include <bits/stdc++.h>
using namespace std;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << qmi(a, b, c) << endl;
    return 0;
}