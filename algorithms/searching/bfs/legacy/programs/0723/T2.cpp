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