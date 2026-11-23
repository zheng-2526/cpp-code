// 题意或用途（据代码整理）：按指令处理定长字符段：r 删除数字，c 转小写，C 转大写。
// 阅读要点：逐字节按 ASCII 区间分类后输出。scanf 格式尾部空白会吞掉输入中的连续空白，需留意对开头空格的影响。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d ", &n);
    while(n--) {
        char c;
        int x;
        scanf("%c %d ", &c, &x);
        if(c == 'r') {
            c = getchar();
            for(int i = 1; i <= x; i++) {
                if(!(c >= '0' && c <= '9')) {
                    printf("%c", c);
                }
                c = getchar();
            }
            printf("\n");
        }
        else if(c == 'c') {
            c = getchar();
            for(int i = 1; i <= x; i++) {
                if(!(c >= 'A' && c <= 'Z')) {
                    printf("%c", c);
                }
                else printf("%c", c + 32);
                c = getchar();
            }
            printf("\n");
        }
        else if(c == 'C') {
            c = getchar();
            for(int i = 1; i <= x; i++) {
                if(!(c >= 'a' && c <= 'z')) {
                    printf("%c", c);
                }
                else printf("%c", c - 32);
                c = getchar();
            }
            printf("\n");
        }
    }
    return 0;
}