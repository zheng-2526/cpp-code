// 题意或用途（据代码整理）：读取沿路各对象的位置和速度，用后方追上前方的规则统计最终分组数。
// 阅读要点：从右向左，如果后车更快就按前组速度处理，否则新开一组。实现没有用距离或时间判相遇。

#include<bits/stdc++.h>
using namespace std;

int n;
int p[100005], v[100005];
 
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i] >> v[i];
    }
    int sum = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(v[i] > v[i + 1]) {
            p[i] = p[i + 1];
            v[i] = v[i + 1];
        }
        else sum++;
    }
    cout << sum;
    return 0;
}