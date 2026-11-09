#include <bits/stdc++.h>
using namespace std;

int n, x, t;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if(t == 0) {
            x++;
            continue;
        }
        if(t == 1) {
            cout << i - 1 << ' ' << x;
            return 0;
        }
    }
}