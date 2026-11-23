// 题意或用途（据代码整理）：从第一个词出发，用前一词的第二字符去匹配后一词首字符，求最长接龙。
// 阅读要点：递归枚举未使用词，返回时恢复当前词和使用标记。
// 注意：现有实现读取固定字符下标，假定每条片段足够长。

#include <bits/stdc++.h>
using namespace std;

string s[51], tmp;
bool a[51];
int n, ans;

void dfs(int r) {
    bool flag = false;
    string tmp2;
    for(int i = 1; i <= n; i++) {
        if(a[i]) continue;
        if(tmp[1] != s[i][0]) continue;
        flag = true;
        a[i] = true;
        tmp2 = tmp;
        tmp = s[i];
        dfs(r + 1);
        tmp = tmp2;
        a[i] = false;
    }
    if(!flag) ans = max(ans, r - 1);
}

int main() {
    cin >> n;
    getchar();
    for(int i = 1; i <= n; i++) {
        getline(cin, s[i]);
    }
    tmp = s[1];
    a[1] = true;
    dfs(2);
    cout << ans;
    return 0;
}