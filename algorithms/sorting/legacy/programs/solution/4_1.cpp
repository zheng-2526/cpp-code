// 题意或用途（据代码整理）：先分别把矩阵各行升序，再把各列升序，输出处理后的矩阵。
// 阅读要点：内层都用冒泡交换相邻逆序对，外层分别固定行和列。

#include<bits/stdc++.h>
using namespace std;

int n, m, a[1005][1005];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for(int k = 1; k <= n; k++){              //行排序
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m - i; j++) {
                if(a[k][j] > a[k][j + 1]) swap(a[k][j], a[k][j + 1]);
            }
        }
    }
    for(int k = 1; k <= m; k++){              //列排序
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n - i; j++) {
                if(a[j][k] > a[j + 1][k]) swap(a[j][k], a[j + 1][k]);
            }
        }
    }
    cout << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}