#include <bits/stdc++.h>
using namespace std;

int v,n,t;
int w[40][40],c[40][40];
int dp[10000];
int l[40];

int main(){
    cin >> v >> n >> t;
    for(int i=1; i <= n; i++){
        int W, C, p;
        cin >> W >> C >> p;
        w[p][++l[p]] = W;
        c[p][l[p]] = C;
    }

    for(int i=1; i <= t; i++){
        for(int j=v; j >= 1; j--){
            cout << j << ' ';
            for(int k=1; k <= l[i]; k++){
                if(j >= w[i][k]) dp[j] = max(dp[j], dp[j - w[i][k]] + c[i][k]); 
            }
        }
    }
    cout << dp[v];
    return 0;
}