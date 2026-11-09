#include<bits/stdc++.h> 
using namespace std;

string s[1010], x;
int n, m, num[1010];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= m; i++) {
        cin >> x;
        for(int k = 1; k <= n; k++){
            bool flag = 1;
            for(int j = 0; j < x.size(); j++) {
                if(s[k][j] != x[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) num[k]++;
        }
    }
    for(int i = 1;i <= n; i++) cout << num[i] << ' ';
    return 0;
}