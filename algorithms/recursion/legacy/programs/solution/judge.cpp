// 题意或用途（据代码整理）：判断从 k 出发反复应用 2k+1 或 3k+1 能否得到目标 x。
// 阅读要点：等于目标就成功，大于目标就剪枝，这个剪枝依赖非负输入时状态始终递增。

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