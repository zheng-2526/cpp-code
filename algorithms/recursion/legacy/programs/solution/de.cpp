// 题意或用途（据代码整理）：对多个整数递归枚举因数分解的分支。
// 阅读要点：当 i 整除 n 时递归到 n/i，不限制因子次序，与只数非降因子序列的版本不同。原题对初值中的额外计数项定义未核实。

#include <bits/stdc++.h>
using namespace std;
 
int n,nn,m,l[32678];
 
int f(int n){
    if(n==1) return 0;
    int res=1;
    for(int i=2;i<=n;i++){
        if(i == n) {
            res++;
            break;
        }
        if(n%i==0){
            res+=f(n/i);
        }
    }
    return res;
}
 
int main(){
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>l[i];
    }
    for(int i=1;i<=nn;i++){
        cout<<f(l[i])<<'\n';
    }
    return 0;
}