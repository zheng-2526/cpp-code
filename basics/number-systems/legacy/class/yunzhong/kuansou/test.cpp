#include <bits/stdc++.h>
using namespace std;

int A, B, ans;
string s;
char a[100];

int main() {
    cin >> A;
    getchar();
    getline(cin, s);
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] >= '1' && s[i] <= '9') {
            ans += pow(A, s.size() - 1 - i) * (s[i] - '0');
        }
        if(s[i] >= 'A' && s[i] <= 'F') {
            ans += pow(A, s.size() - 1 - i) * (s[i] - 'A' + 10);
        }
    }
    cin >> B;
    int i;
    for(i = 0; ans != 0; i++) {
        int k = ans % B;
        ans /= B;
        if(k < 10) {
            a[i] = k + '0';
        } else {
            a[i] = k - 10 + 'A';
        }
    }
    for(int j = i - 1; j >= 0; j--) {
        cout << a[j];
    }
    return 0;
}