#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
typedef long long ll;
const int mod = 998244353;
int t,id,n,m;
ll sum, ansc, ansf, cc, f;
ll a[1010][1010], l[1010][1010], c[1010][1010];
int main(){
    cin >> t >> id;
    while(t--){
        cin  >> n >> m >> cc >> f; 
        for(int i = 1;i <= n; i++){
            for(int j = 1;j <= m ; j++){
                char t;
                cin >> t;
                a[i][j] = t-48;
            }
        }
        for(int i = 1; i <= m; i++){
            c[n+1][i] = -1;
            for(int j = n;j >= 1; j--){
                if(a[j][i] == 0) c[j][i] = c[j+1][i] + 1;
                else c[j][i] = -1;
            }
        }
        for(int i = 1;i <= n; i++){
            l[i][m+1] = -1;
            for(int j = m; j >= 1; j--){
                if(a[i][j] == 0) l[i][j] = l[i][j+1] + 1;
                else l[i][j] = -1;
            }
        }
        for(int i = 1; i <= m; i++){
            int j = 1;
            ll sum = 0;
            while(j <= n){
                if(a[j][i] == 1 || a[j-1][i] == 1 || a[j-2][i] == 1){
                    j += 1;
                    sum = 0;
                    continue;
                }
                if(j - 2 <= 0){
                    j++;
                    continue;
                }
                sum += l[j-2][i];
                ansc = (ansc + l[j][i] * sum) % mod;
                ansf = (ansf + c[j][i] * l[j][i]*sum) % mod;
                j++;
            }
        }
        cout << ansc * cc % mod << " " <<ansf * f % mod << endl;
        ansc = ansf = 0;
        memset(l,0,sizeof(l));
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
    }
    return 0;
}