// 题意或用途（据代码整理）：把连续的 6 按长度替换：至多 3 个保留，4 至 9 个写 9，更多写 27。
// 阅读要点：遇到 6 时读完整段，再输出段后遇到的第一个其他字符。
// 注意：旧代码没有检查段内的读取返回值，输入恰好以 6 结束时要特别留意。

#include <bits/stdc++.h>
using namespace std;

int n;
char c;

int main() {
    while(~scanf("%c", &c)) {
        if(c == '6')  {
            n = 0;
            while(1) {
                n++;
                scanf("%c", &c);
                if(c != '6') break;
            }
            if(n <= 3) {
                for(int i = 1; i <= n; i++) printf("6");
            }
            else if(n <= 9) printf("9");
            else printf("27");
            printf("%c", c);
        }
        else printf("%c", c);
    }
    return 0;
}