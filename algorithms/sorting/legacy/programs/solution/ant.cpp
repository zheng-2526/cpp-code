// 题意或用途（据代码整理）：把范围在 1 到 1000 的整数按升序输出。
// 阅读要点：记录每个值出现的次数，再按数值从小到大输出足够多次，这是计数排序的基础写法。

#include <bits/stdc++.h>
using namespace std;

int a[1005], n;

int main() {
    cin >> n;
    int tem;
    for(int i = 1; i <= n; i++) {
        cin >>tem;
        a[tem]++;
    }
    for(int i = 1; i <= 1000; i++) {
        while(a[i]--) {
            cout << i << ' ';
        }
    }
    return 0;
}