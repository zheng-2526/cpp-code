// 题意或用途（据代码整理）：按类别选 1.26 或 2.455 的系数，换算输入值并与阈值比较，输出两位小数及表情。
// 阅读要点：三元表达式选系数。
// 注意：scanf 的 %d 参数必须指向 int，此处传入 bool 指针不符合要求。

#include <bits/stdc++.h>
using namespace std;

double rp, rd, ans;
bool s;

int main() {
    scanf("%lf%d%lf", &rp, &s, &rd);
    ans = rp * (s ? 1.26 : 2.455);
    printf("%.2lf ", ans);
    if(ans > rd) printf("T_T");
    else printf("^_^");
    return 0;
}