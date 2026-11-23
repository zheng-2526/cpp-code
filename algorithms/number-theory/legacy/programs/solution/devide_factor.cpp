// 题意或用途（据代码整理）：统计将正整数拆成若干个大于 1 的因子之积的方案数。
// 阅读要点：递归只枚举不小于上一因子的候选，用因子非降顺序去掉排列重复。

#include <bits/stdc++.h>
using namespace std;

int coun(int n, int start=2) {
    if(n == 1) return 1;
    int count = 0;
    for(int i=start; i<=n; i++) {
        if(n%i == 0) {
            if(i == n) count++;
            else count += coun(n/i, i);
        }
    }
    return count;
}

int main() {
    int n, a;
    cin >> n;
    while(n--) {
        cin >> a;
        cout << coun(a) << endl;
    }
    return 0;
}