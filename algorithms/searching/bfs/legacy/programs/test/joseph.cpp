#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> q;
string s[1005];

int main() {
    freopen("joseph.in", "r", stdin);
    freopen("joseph.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        q.push(i);
    int k = 1;
    while(!q.empty()){
        if(k % m == 0){
            int x = q.front();
            q.pop();
            cout << x << ' ' << s[x] << '\n';
            k = 0;
        } else {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        k = k + 1;
    }
    return 0;
}