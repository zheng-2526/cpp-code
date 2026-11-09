#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,m,a,b,x[N],y[N],z[N],ans;
int main(){
    cin>>n>>m>>a>>b;
    //每次选择最早空闲的机器人给下一根青菜洗菜
    for(int i=1;i<=n;i++){
        int p=x[1],q=1;
        for(int j=2;j<=m;j++){
            if(x[j]<p){
                p=x[j];
                q=j;
            }
        }
        y[i]=x[q]+a,x[q]=y[i];
    }
    sort(y+1,y+n+1);
    for(int i=1;i<=m;i++) z[i]=x[i];
	// 将各机器人在完成洗菜之后的空闲时间复制到新的数组中，
    // 这就是水煮任务开始时各机器人可用的起始时间
    for(int i=1;i<=n;i++){
        int p=z[1],q=1;
        for(int j=2;j<=m;j++){
            if(z[j]<p){
                p=z[j];
                q=j;
            }
        }
        z[q]=max(z[q],y[i])+b;
    }
    for(int i=1;i<=m;i++) ans=max(ans,z[i]);
    cout<<ans;
}