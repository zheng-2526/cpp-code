// 题意或用途（据代码整理）：判断西瓜重量能否分成两份正偶数。
// 阅读要点：必须是大于 2 的偶数，最低位可用来判断奇偶。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    if(a > 2 && !(a & 1)) printf("YES");
    else printf("NO");
    return 0;
}