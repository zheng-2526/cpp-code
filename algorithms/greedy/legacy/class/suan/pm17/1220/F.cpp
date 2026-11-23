// 题意或用途（据代码整理）：删除若干数字以尝试得到尽可能小的十进制数。
// 阅读要点：找到第一个比右邻大的数字就删除并左移后缀。
// 注意：这份草稿仍输出调试信息，搜索边界随剩余次数缩小，不能视为完整解。

#include<bits/stdc++.h>
using namespace std;

int a[1005], n;
string s;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        a[i + 1] = s[i] - '0';
    }
    int x = s.size();
    scanf("%d", &n);
    while(n--) {
        printf("%d %d\n", n, x);
        for(int i = 1; i <= n; i++) {
            if(a[i] > a[i + 1]) {
                for(int j = i; j <= x + 1; j++) {
                    a[j] = a[j + 1];
                }
                x--;
                break;
            }
        }
    }
    int y = 1;
    while(!a[y]) {
        y++;
    }
    for(int i = y; i <= x; i++) {
        printf("%d", a[i]);
    }
    return 0;
}