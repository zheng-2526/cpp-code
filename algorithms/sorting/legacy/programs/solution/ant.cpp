#include <bits/stdc++.h>
using namespace std;

int a[1005], n;

int main() {
    cin >> n;
    int tem;
    for(int i = 1; i <= n; i++) {
        cin >>tem;
        a[tem]++;
    }
    for(int i = 1; i <= 1000; i++) {
        while(a[i]--) {
            cout << i << ' ';
        }
    }
    return 0;
}