// 题意或用途（据代码整理）：用反复选择的思路重新排列数组。
// 阅读要点：第 i 轮在前缀 [1,i] 选最小值换到 i。
// 注意：前缀的范围与增序扫描的方向组合不正确，较早的元素可能被反复打乱，适合当作排序边界辨析。

#include<bits/stdc++.h>
using namespace std;
long long a,b[10009],sb,lhl;
int main(){
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
    }
    for(int i=1;i<=a;i++){
        lhl=1000000000000;
        for(int j=i;j>=1;j--){
            if(b[j]<lhl){
                lhl=b[j];
                sb=j;
            }
        }
        swap(b[i],b[sb]);
    }
//  sort(b,b+a+1);
    for(int i=1;i<=a;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}