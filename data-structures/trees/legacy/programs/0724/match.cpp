#include<bits/stdc++.h>
using namespace std;

int a[1024], b[1024], n;

int main() {
    cin >> n;
    int x = pow(2, n);
    int j = 1;
    for (int i = pow(2, n); i <= pow(2, n + 1) - 1; i++) {
        cin >> a[i];
        b[i] = j;
        j++;
    }
    while(n--) {
        for(int i = pow(2, n); i <= pow(2, n + 1) - 1; i++) {
            a[i] = max(a[2 * i], a[2 * i + 1]);
            a[2 * i] > a[2 * i + 1] ? b[i] = b[2 * i] : b[i] = b[2 * i + 1];
        }
    }
    cout << b[2] + b[3] - b[1];
    return 0;
}