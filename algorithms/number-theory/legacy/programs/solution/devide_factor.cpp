#include <bits/stdc++.h>
using namespace std;

int coun(int n, int start=2) {
    if(n == 1) return 1;
    int count = 0;
    for(int i=start; i<=n; i++) {
        if(n%i == 0) {
            if(i == n) count++;
            else count += coun(n/i, i);
        }
    }
    return count;
}

int main() {
    int n, a;
    cin >> n;
    while(n--) {
        cin >> a;
        cout << coun(a) << endl;
    }
    return 0;
}