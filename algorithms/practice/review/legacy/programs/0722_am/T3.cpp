#include<bits/stdc++.h>
using namespace std;

int n;
int p[100005], v[100005];
 
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i] >> v[i];
    }
    int sum = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(v[i] > v[i + 1]) {
            p[i] = p[i + 1];
            v[i] = v[i + 1];
        }
        else sum++;
    }
    cout << sum;
    return 0;
}