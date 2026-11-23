// 题意或用途（据代码整理）：求 n 个数中严格大于程序计算的整数平均值的个数。
// 阅读要点：先读入并求和，再扫描计数。整数除法会向零截断。

#include<bits/stdc++.h> 
using namespace std;

int x[100005], n, avr, ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        avr += x[i];
    }
    avr = avr / n;
    for(int i = 1; i <= n; i++)
        if(x[i] > avr) ans++;
    cout << ans;
    return 0;
}