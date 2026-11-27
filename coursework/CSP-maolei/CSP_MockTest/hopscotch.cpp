// 跳房子：广度优先搜索求最少跳数，每个落点只扫描一次。
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> to, r, dis, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    to.resize(n + 1);
    r.resize(n + 1);
    dis.assign(n + 1, -1);
    q.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        to[i] = i - x;
    }
    for(int i = 1; i <= n; i++) {
        long long k; cin >> k;
        r[i] = i + (int)min(k, (long long)n - i);
    }
    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int head = 1, tail = 1, j = 2;
    q[1] = 1;
    dis[1] = 0;
    while(head <= tail) {
        int x = q[head++];
        if(r[x] == n) {
            cout << dis[x] + 1 << '\n';
            return 0;
        }
        // 停留位置不超过已扫描的最大落点。j 可以从上次的位置继续往右扫。
        for(; j <= r[x]; j++) {
            int y = to[j];
            if(dis[y] == -1) {
                dis[y] = dis[x] + 1;
                q[++tail] = y;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
