#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
struct Toy{
    int dir;
    string name;
}toy[100005];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>toy[i].dir>>toy[i].name;
    for(int i=1;i<=m;i++){
        int foot,dir;
        scanf("%d %d",&dir,&foot);
        foot=((dir==0&&toy[cnt].dir==1)||(dir==1&&toy[cnt].dir==0)?1:-1)*foot;
        if(foot>0){
            foot%=n;
            if(foot==0)foot=n;
            cnt=foot+cnt;
            if(cnt>n)cnt-=n;
        }
        if(foot<0){
            foot=(-foot)%n;
            if(foot==0)foot=-n;
            else foot*=-1;
            cnt=foot+cnt;
            if(cnt<0)cnt+=n;
        }
    }
    cout<<toy[cnt].name;
    return 0;
}