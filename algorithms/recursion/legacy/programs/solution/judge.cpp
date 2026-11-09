#include<bits/stdc++.h>
using namespace std;
bool rec(int k,int x){
    if(k==x) return true;
    if(k>x) return false;
    return rec(2*k+1,x)||rec(3*k+1,x);
}
int main(){
    int k,x;
    char c;
    cin>>k>>c>>x;
    if(rec(k,x))
        cout<<"YES";
    else
        cout<<"NO";
}