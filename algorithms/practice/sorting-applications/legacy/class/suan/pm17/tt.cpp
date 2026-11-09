#include<bits/stdc++.h>
using namespace std;
long long cnt=0,n,mu[55033],tu[55033]; 
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&mu[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&tu[i]);
    }
    sort(mu+1,mu+n+1);
    sort(tu+1,tu+n+1);
    long long x=1,y=1;
    while(x<=n&&y<=n){
        printf("1\n");
        if(mu[x]<=tu[y]){
            x++;
        }else{
            x++;
            y++;
            cnt++;
        }
    }
    printf("%lld",cnt);
}