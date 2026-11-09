#include <bits/stdc++.h>
using namespace std;

int c[2005][2005];
int s[2005][2005];

int main() {
    int t, k;
    cin >> t >> k;
    int n, m;
    for (int i = 1; i <= 2000; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (i == j) {
                c[i][j] = 1 % k;
            }
            else if (j == 1) {
                c[i][j] = i % k;
            }
            else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            }
            if (i == j) {
                s[i][j] = s[i][j - 1];
            }
            else {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
            if (c[i][j] == 0) {
                s[i][j]++;
            }
        }
    }
    while (t--) {
        cin >> n >> m;
        cout << s[n][min(n, m)] << "\n";
    }
    return 0;
}