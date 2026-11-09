#include<bits/stdc++.h> 
using namespace std;

int x, y;

int main() {
    cin >> x;
    while(x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    cout << y;
    return 0;
}