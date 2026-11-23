// 题意或用途（据代码整理）：从 1 至 n 选 m 个数字，按递增顺序输出各组合。
// 阅读要点：递归传入下一位最小候选 b，并用剩余位置数收紧上界，防止后面凑不够数。

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