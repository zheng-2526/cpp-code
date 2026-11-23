// 题意或用途（据代码整理）：判断六位票号的前三位和后三位数字之和是否相同。
// 阅读要点：用取余拆两组三位，遇到前导零自然会把相应位计为 0。

#include <bits/stdc++.h>
using namespace std;

int T, n, ans1, ans2;

int main() {
    scanf("%d", &T);
    while(T--) {
        ans1 = ans2 = 0;
        scanf("%d", &n);
        for(int i = 1; i <= 3; i++) {
            ans1 += (n % 10);
            n /= 10;
        }
        for(int i = 1; i <= 3; i++) {
            ans2 += (n % 10);
            n /= 10;
        }
        if(ans1 == ans2) printf("You are lucky!\n");
        else printf("Wish you good luck.\n");
    }
    return 0;
}