// 题意或用途（据代码整理）：跳过标题含 qiandao 或 easy 的题目，输出第 m+1 道其余题目；不足则输出固定提示。
// 阅读要点：find 返回 npos 表示没找到，先标记应跳过的标题，再数剩余题。

#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
string s[31];
bool a[31];

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 1; i <= n; i++) {
        getline(cin, s[i]);
        if(s[i].find("qiandao") != string::npos || s[i].find("easy") != string::npos)
            a[i] = 1;
    }
    // for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    for(int i = 1; i <= n; i++) {
        if(a[i]) continue;
        ans++;
        if(ans == m + 1) {
            cout << s[i];
            return 0;
        }
    }
    cout << "Wo AK le";
    return 0;
}