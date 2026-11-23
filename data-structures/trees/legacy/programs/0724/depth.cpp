// 题意或用途（据代码整理）：读取以编号 1 为根的二叉树，求最大深度，根深度为 1。
// 阅读要点：左右孩子非零时递归，该层深度通过参数传递，答案取所有访问深度最大值。

#include <bits/stdc++.h>
using namespace std;

int a[1000005][3], n, ans;

 void dfs(int no, int de) {
    ans = max(ans, de);
    if (a[no][1]) {
        dfs(a[no][1], de + 1);
    }
    if (a[no][2]) {
        dfs(a[no][2], de + 1);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2];
    }
    dfs(1, 1);
    cout << ans;
    return 0;
}