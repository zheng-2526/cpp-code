// 题意或用途（据代码整理）：把第四个输入按每 4 个一组换算后，与前三项一起取最小值。
// 阅读要点：当四项分别代表资源所能支持的份数时，最小值就是瓶颈。原资源含义未确认。

#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    d /= 4;
    cout << min(a, min(b, min(c, d)));
    return 0;
}