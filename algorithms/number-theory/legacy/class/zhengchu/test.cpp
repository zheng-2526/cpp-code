// 题意或用途（据代码整理）：输入 m，比较 2m 与相邻整数的乘积，输出 floor(sqrt(2m)) 或其下一整数。
// 阅读要点：代码只特判恰好满足 t(t+1)=2m 的情况，原题所求未核实，不能直接当作通用反三角数公式。

#include<bits/stdc++.h>
using namespace std;

int m;

int main() {
    cin >> m;
    if(int(sqrt(2 * m)) * (int(sqrt(2 * m)) + 1) == 2 * m) cout<< int(sqrt(2 * m));
    else cout << int(sqrt(2 * m)) + 1;
}