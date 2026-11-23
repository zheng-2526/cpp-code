// 题意或用途（据代码整理）：枚举并输出三位水仙花数。
// 阅读要点：逐位取出数字，累加位数字的立方，和原数相等就是水仙花数。

#include <bits/stdc++.h>
using namespace std;

bool isShuixianhua(int x) {
    int sum = 0, temp = x;
    while (temp > 0) {
        sum += (temp % 10) * (temp % 10) * (temp % 10);
        temp /= 10;
    }
    return sum == x;
}

int main() {
    for(int i = 100; i <= 1000; i++) {
        if(isShuixianhua(i)) {
            cout << i << '\n';
        }
    }
}