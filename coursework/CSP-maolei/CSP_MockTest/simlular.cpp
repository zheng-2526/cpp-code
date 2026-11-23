// 题意或用途（据代码整理）：读取两组单词，忽略英文大小写，输出去重后的交集大小与并集大小。
// 阅读要点：先将 A-Z 统一成小写，map 记录单词出现次数。首次出现时保存到数组，并集大小用两组去重数相加再减交集。

#include <bits/stdc++.h>
using namespace std;

string s1[10005], s2[10005], s;
map<string, int> mp1, mp2;
int n, m, a, b, t1, t2, ans;

void transfer() {
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        transfer();
        if(mp1[s]++);else s1[++t1] = s;
    }
    for(int i = 1; i <= m; i++) {
        cin >> s;
        transfer();
        if(mp2[s]++);else s2[++t2] = s;
    }
    for(int i = 1; i <= t1; i++) {
        // s1 中每词仅出现一次，查第二组是否出现即可求去重交集。
        if(mp2[s1[i]]) ans++;
    }
    cout << ans << '\n' << t1 + t2 - ans;
}