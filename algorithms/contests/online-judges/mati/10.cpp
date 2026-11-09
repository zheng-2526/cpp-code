#include<bits/stdc++.h> 
using namespace std;

int x[100005], n, avr, ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        avr += x[i];
    }
    avr = avr / n;
    for(int i = 1; i <= n; i++)
        if(x[i] > avr) ans++;
    cout << ans;
    return 0;
}