#include<bits/stdc++.h>
using namespace std;
int h[10];
int n,d,x,maxh = 0;
int dx[4][4] = {{0,0,0,1},{0,1,2,0},{0,1,1,1},{2,0,1,2}};
int dy[4][4] = {{0,1,2,2},{0,0,0,1},{0,0,1,2},{0,1,1,1}};
bool check(int x,int h1,int id){
    for(int i=0;i<4;i++)if(h1-dy[id][i]<=h[x+dx[id][i]])return 0;
    return 1;
}
void drop(){
    int h1 = maxh + 4;
    while(check(x,h1-1,d))h1--;
    for(int i=0;i<4;i++)if(h1-dy[d][i]>h[x+dx[d][i]]){
        h[x+dx[d][i]]=h1-dy[d][i];
        maxh=max(maxh,h[x+dx[d][i]]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d>>x;
        d/=90;
        drop();
    }
    for(int i=1;i<=8;i++)cout<<h[i]<<' ';
    return 0;
}