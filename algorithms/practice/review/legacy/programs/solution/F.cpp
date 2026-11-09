#include <bits/stdc++.h>
using namespace std;

int x, y, a;

int main() {
    cin >> x >> y;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++){
            char c;
            cin >> c;
            if(c == '.') a++;
        }
    }
    // cout << a << ' ';
    if((a - (x + y - 1)) % 2) printf("niuniu");
    else printf("niumei");
    return 0;
}