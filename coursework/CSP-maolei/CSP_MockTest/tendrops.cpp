// 十滴水：按坐标排序，用双向链表维护邻居，小根堆选出最左侧的爆点。
#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
struct Node {
    int x, w;
} a[N];

int c, m, n, pre[N], nxt[N];
priority_queue<int, vector<int>, greater<int>> q;

void add(int i) {
    // 刚达到 5 滴时入队，等待爆开期间继续加水也只处理一次。
    if(++a[i].w == 5) q.push(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> m >> n;
    for(int i = 1; i <= m; i++) cin >> a[i].x >> a[i].w;
    sort(a + 1, a + m + 1, [](const Node& u, const Node& v) {
        return u.x < v.x;
    });

    for(int i = 1; i <= m; i++) {
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    nxt[m] = 0;

    int ans = m;
    while(n--) {
        int p; cin >> p;
        int id = (int)(lower_bound(a + 1, a + m + 1, p, [](const Node& u, int x) {
            return u.x < x;
        }) - a);
        add(id);

        while(!q.empty()) {
            int i = q.top();
            q.pop();
            a[i].w = 0;
            ans--;

            int l = pre[i], r = nxt[i];
            if(l) {
                nxt[l] = r;
                add(l);
            }
            if(r) {
                pre[r] = l;
                add(r);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
