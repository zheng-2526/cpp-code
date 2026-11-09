#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,max=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        c=c+a-b;
        if(c>max)
        {
            max=c;
        }
        cout << max << '\n';
    }
    cout<<c;
    return 0;
}