#include<bits/stdc++.h>
using namespace std;
int a[100005]={0},n,m,v[100005]={0};
void dg(int i,int b){
    if(i==m){
        for(int j=b;j<=n;j++){
            v[i]=j;
            for(int j=1;j<=m;j++){
                printf("%3d",v[j]);
            }
            cout<<'\n';
        }
        return;
    }
    for(int j=b+1;j<=n-m+i+1;j++){
        v[i]=j-1;
        dg(i+1,j);
    }
}
int main(){
    cin>>n>>m;
    dg(1,1);
    return 0;
}