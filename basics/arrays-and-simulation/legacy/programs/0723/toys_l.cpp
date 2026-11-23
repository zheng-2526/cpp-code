// 题意或用途（据代码整理）：执行一组圆环移动指令，根据当前位置的面向决定正反方向。
// 阅读要点：数组分别存朝向、名字、指令步数，oi 是当前位置。
// 注意：取模可能得到 0，实际数组从 1 编号，边界有待核对。

#include<bits/stdc++.h>
using namespace std;
const int s=1e5+10;
int n,m,num,mk,fot[s],oi=1;
char a[s][15];
int zz[s],zt[s];
int main(){
    cin >>n >>m;
    num=n;
    while(n--){
        cin >>zt[num-n] >>a[num-n];
    }
    mk=m;
    while(m--){
        cin >>zz[mk-m] >>fot[mk-m];
    }
    for(int i=1;i<=mk;++i){
        if(zt[oi]&&zz[i]||!zt[oi]&&!zz[i]){
            oi-=fot[i];
        }
        if(!zt[oi]&&zz[i]||zt[oi]&&!zz[i]){
            oi+=fot[i];
        }
        if(oi<=0){
            while(oi<=0) oi+=num*100;
            oi%=num;
        }
        if(oi>num)   oi%=num;    
    }
    cout <<a[oi];
    return 0;
}