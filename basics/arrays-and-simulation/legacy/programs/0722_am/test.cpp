// 题意或用途（据代码整理）：根据当前角色朝向，把相对左右命令换算为圆环上的下标偏移。
// 阅读要点：先按 n 取余，再调整越界位置，最后输出落点名字。
// 注意：原版本负方向可能得到 0，与一基下标的约定不符。

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