// 题意或用途（据代码整理）：给出每层的跳幅，可向上或向下跳该幅度，求最少几次从 a 到 b。
// 阅读要点：每层视为无权图的一个点，最多两条合法边。队列里的 second 是累计步数。

#include <bits/stdc++.h>
using namespace std;

int ch[20005], n, a, b;
bool visited[20005];
queue<pair<int, int>> q;

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> ch[i];
    }
    q.push({a, 0});
    while(!q.empty()) {
        if (visited[q.front().first]) {
            q.pop();
            continue;
        }
        visited[q.front().first] = true;
        if(q.front().first + ch[q.front().first] <= n) {
            q.push({q.front().first + ch[q.front().first], q.front().second + 1});
        }
        if(q.front().first - ch[q.front().first] >= 1) {
            q.push({q.front().first - ch[q.front().first], q.front().second + 1});
        }
        if(q.front().first == b) {
            cout << q.front().second;
            return 0;
        }
    }
    cout << -1;
    return 0;
}