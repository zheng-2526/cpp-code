// 题意或用途（据代码整理）：输入每轮增加、减少的数量，输出各轮后的历史最高净值，最后输出当前净值。
// 阅读要点：c 跟踪当前累计量，max 只在突破最高值时更新。

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,max=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        c=c+a-b;
        if(c>max)
        {
            max=c;
        }
        cout << max << '\n';
    }
    cout<<c;
    return 0;
}