// 题意或用途（据代码整理）：从 1 至 n 选取 m 个互不相同的数并排列，输出各排列和总个数。
// 阅读要点：book 标记路径内已经选的数，返回上一层时恢复标记，以便进入下一条分支。

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[6+9],book[6+9],h;
void dfs(int step){
    if(step==m){
        h++;
        for(int i=0;i<m;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(book[i]==0){
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    dfs(0);
    cout<<"number="<<h;
    return 0;
}