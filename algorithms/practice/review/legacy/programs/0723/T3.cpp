// 题意或用途（据代码整理）：按给定顺序移除位置，每次累加其最近的左右未移除位置的值。
// 阅读要点：chosen 相当于删除标记，往两边跳过已删除项，单次最坏可能扫过整段。

#include <bits/stdc++.h>
using namespace std;

int num[100005], n, ans, ord[100005];
bool chosen[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> ord[i];
    }

    for(int i = 1; i <= n; i++) {
        int j = ord[i] - 1;
        chosen[ord[i]] = true;
        while(j >= 1 && chosen[j]) {
            j--;
        }
        if(j >= 1) {
          ans += num[j];
        }
        j = ord[i] + 1;
        while(j <= n && chosen[j]) {
            j++;
        }
        if(j <= n) {
          ans += num[j];
        }
    }
    cout << ans << endl;
    return 0;
}