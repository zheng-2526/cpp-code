// 题意或用途（据代码整理）：尝试对带配对信息的记录排序，第一列做主键，第二列取原序列后继。
// 阅读要点：交换两条记录时两列一起交换。
// 注意：程序目前没有输出，属于排序实验。

#include <bits/stdc++.h>
using namespace std;

int a[1005][2], n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }
    for(int i = 1; i < n; i++) {
        a[i][1] = a[i + 1][0];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(a[j][0] > a[j + 1][0]) {
                swap(a[j][0], a[j + 1][0]);
                swap(a[j][1], a[j + 1][1]);
            }
        }
    }
}