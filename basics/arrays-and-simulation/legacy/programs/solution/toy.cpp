// 题意或用途（据代码整理）：从圆环上的第一人出发，按题设方向规则移动，输出最终落点的人名。
// 阅读要点：朝向与命令不同则正向移动，否则反向。用循环把下标归回 1..n。

#include <bits/stdc++.h>
using namespace std;
 
struct node{
    int side;
    string name;
} mens[100010];
 
int n,m,point=1,s,num;
 
bool left_or_right(int man,int hand){
    if((man+hand)%2==0){
        return 0;
    }
    else return 1;
}
 
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>mens[i].side>>mens[i].name;
    }
    for(int i=1;i<=m;i++){
        cin>>s>>num;
        if(left_or_right(mens[point].side,s)){
            point+=num;
        }
        else point-=num;
        while(point<1){
            point+=n;
        }
        while(point>n){
            point-=n;
        }
    }
    cout<<mens[point].name;
    return 0;
}