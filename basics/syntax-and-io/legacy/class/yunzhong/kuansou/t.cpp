// 题意或用途（据代码整理）：观察全局整数 i 从零初始化后，前置自增作为 while 条件的效果。
// 阅读要点：在合法的正整数范围内条件始终为真，最终会触发有符号整数溢出，不是正常退出的计数循环。

#include <bits/stdc++.h>
using namespace std;

int i;

int main() {
    while(++i) cout<<i<<' ';
}