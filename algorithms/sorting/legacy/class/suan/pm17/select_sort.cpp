#include<bits/stdc++.h>
using namespace std;
long long a,b[10009],sb,lhl;
int main(){
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
    }
    for(int i=1;i<=a;i++){
        lhl=1000000000000;
        for(int j=i;j>=1;j--){
            if(b[j]<lhl){
                lhl=b[j];
                sb=j;
            }
        }
        swap(b[i],b[sb]);
    }
//  sort(b,b+a+1);
    for(int i=1;i<=a;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}