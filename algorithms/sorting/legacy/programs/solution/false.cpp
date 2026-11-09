#include <bits/stdc++.h>
using namespace std;

int a[1005][2], n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }
    for(int i = 1; i < n; i++) {
        a[i][1] = a[i + 1][0];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(a[j][0] > a[j + 1][0]) {
                swap(a[j][0], a[j + 1][0]);
                swap(a[j][1], a[j + 1][1]);
            }
        }
    }
}