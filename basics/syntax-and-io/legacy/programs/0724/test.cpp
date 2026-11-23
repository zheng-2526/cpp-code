// 题意或用途（据代码整理）：输出 ASCII 码 13 对应的回车控制字符。
// 阅读要点：char(13) 是字符而非数字文本 13，实际显示取决于终端。

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << char(13);
}