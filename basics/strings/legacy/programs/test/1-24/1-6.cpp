// 题意或用途（据代码整理）：逐行查找 chi1 huo3 guo1，遇到单独一个点终止，输出总行数、最早命中行号和命中行数。
// 阅读要点：每行只用 find 判断是否包含目标片段，同一行即使出现多次也只计一次。

#include <bits/stdc++.h>
using namespace std;

string s;
int n, ans1, ans2;
bool flag;

int main() {
    while(getline(cin, s)) {
        if(s == ".") break;
        n++;
        if(s.find("chi1 huo3 guo1") != string::npos) {
            if(!flag) {
                flag = 1;
                ans1 = n;
            }
            ans2++;
        }
    }
    printf("%d\n", n);
    if(flag) {
        printf("%d %d", ans1, ans2);
    }
    else printf("-_-#");
    return 0;
}