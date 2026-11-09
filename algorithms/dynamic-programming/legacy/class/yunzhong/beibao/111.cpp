#include<bits/stdc++.h>
using namespace std;
int a[20001];
int b[101][2];//数组第二列[0]表示重量，[1]表示价值
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i][0]>>b[i][1];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=m;i>=1;i--)
        {
            int k=0;
            while(i>=k*b[j][0])
            {
                a[j][i]=max(a[j-1][i],a[j-1][i-b[j][0]*k]+b[j][1]*k);
                k++;
            }
        }
    }
    cout<<a[m];
    return 0;
}