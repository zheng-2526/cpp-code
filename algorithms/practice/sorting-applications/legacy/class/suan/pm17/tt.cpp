// 题意或用途（据代码整理）：统计两个序列可以组成的最大严格优势对数，每个数最多用一次。
// 阅读要点：排序后采用双指针，用最小的可赢元素匹配对侧当前最小值。
// 注意：循环里的 printf 会额外输出调试行。

#include<bits/stdc++.h>
using namespace std;
long long cnt=0,n,mu[55033],tu[55033]; 
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&mu[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&tu[i]);
    }
    sort(mu+1,mu+n+1);
    sort(tu+1,tu+n+1);
    long long x=1,y=1;
    while(x<=n&&y<=n){
        printf("1\n");
        if(mu[x]<=tu[y]){
            x++;
        }else{
            x++;
            y++;
            cnt++;
        }
    }
    printf("%lld",cnt);
}