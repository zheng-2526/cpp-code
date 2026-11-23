// 题意或用途（据代码整理）：尝试按 n、d 计算模 1000000007 的递推序列，原题含义未知。
// 阅读要点：d=1 分支反复乘 4，其他分支引用 i-1 和 i-d 两个状态。
// 注意：普通分支末尾缺分号，也没有输出。

#include<bits/stdc++.h> 
using namespace std;

const int mod = 1e9 +7;
int n, d, ans[1005];

int main() {
    ans[0] = 1;
    cin >> n >> d;
    if(d == 1) {
        for(int i = 1; i <= n; i++) ans[i] = ans[i - 1] * 4 % mod;
        cout << ans[n];
        return 0;
    }
    for(int i = 1; i < d; i++) ans[i] = i * 2 + 1;
    for(int i = d; i <= n; i++) ans[i] = 2 + ans[i - 1] + ans[i - d ]
    return 0;
}