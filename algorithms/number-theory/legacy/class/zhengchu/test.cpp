#include<bits/stdc++.h>
using namespace std;

int m;

int main() {
    cin >> m;
    if(int(sqrt(2 * m)) * (int(sqrt(2 * m)) + 1) == 2 * m) cout<< int(sqrt(2 * m));
    else cout << int(sqrt(2 * m)) + 1;
}