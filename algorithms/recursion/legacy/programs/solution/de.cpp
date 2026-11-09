#include <bits/stdc++.h>
using namespace std;
 
int n,nn,m,l[32678];
 
int f(int n){
    if(n==1) return 0;
    int res=1;
    for(int i=2;i<=n;i++){
        if(i == n) {
            res++;
            break;
        }
        if(n%i==0){
            res+=f(n/i);
        }
    }
    return res;
}
 
int main(){
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>l[i];
    }
    for(int i=1;i<=nn;i++){
        cout<<f(l[i])<<'\n';
    }
    return 0;
}