// 题意或用途（据代码整理）：分组背包：每组最多选一件物品，求容量内的最大价值。
// 阅读要点：按组处理并倒序扫容量，同一容量枚举组内候选，防止一组被重复取用。
// 注意：程序会额外打印容量 j，属于调试输出。

#include <bits/stdc++.h>
using namespace std;

int v,n,t;
int w[40][40],c[40][40];
int dp[10000];
int l[40];

int main(){
    cin >> v >> n >> t;
    for(int i=1; i <= n; i++){
        int W, C, p;
        cin >> W >> C >> p;
        w[p][++l[p]] = W;
        c[p][l[p]] = C;
    }

    for(int i=1; i <= t; i++){
        for(int j=v; j >= 1; j--){
            cout << j << ' ';
            for(int k=1; k <= l[i]; k++){
                if(j >= w[i][k]) dp[j] = max(dp[j], dp[j - w[i][k]] + c[i][k]); 
            }
        }
    }
    cout << dp[v];
    return 0;
}