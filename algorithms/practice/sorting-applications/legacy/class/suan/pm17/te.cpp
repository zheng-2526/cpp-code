#include <bits/stdc++.h>
using namespace std;

int i,n,a[100010];
long long ans;

void re(int &x)
{
    x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

bool cmp(const int x,const int y)
{
    return x<y;
}

int main()
{
    re(n);
    for(i=1;i<=n;i++)
        re(a[i]);
    sort(a+1,a+n+1,cmp);//按用时由小到大排序
    while(n>3)
    {
        ans+=min(a[1]*2+a[n]+a[n-1],a[1]+a[2]*2+a[n]);//根据公式累加
        n-=2;//每次此岸人数减少2人
    }
    if(n==2) ans+=a[2];//此岸人数n为2或3时
    if(n==3) ans+=a[1]+a[2]+a[3];
    printf("%lld",ans);
    return 0;
}