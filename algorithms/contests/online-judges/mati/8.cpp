// 题意或用途（据代码整理）：针对每个窗口长度 l，统计所有长度为 l 的连续区间的不同值个数之和。
// 阅读要点：滑窗中用频次维护不同值数量，理想做法在频次 0 到 1 与 1 到 0 时更新计数。
// 注意：现有代码移出下标写成 i-l-1，且数组读入的格式和变量类型不一致。

#include<bits/stdc++.h> 
using namespace std;

long long n, m, a[1000006], l, num[1000006], x, ans;

int main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while(m--){
        for(int i = 1; i <= 1000000; i++) num[i] = 0;
        x = ans = 0;
        scanf("%lld", &l);
        // cout << '\n';
        for(int i = 1; i <= l; i++) {
            if(!num[a[i]]) x++;
            num[a[i]] ++;
        }
        ans += x;
        // cout << x << '\n';
        for(int i = l + 1; i <= n; i++) {
            if(!num[a[i]]) x++;
            if(num[a[i - l - 1]] == 1) x--;
            num[a[i]] += 1;
            num[a[i - l - 1]] -= 1;
            ans += x;
            // cout << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << x << '\n';
        }
        printf("%lld\n", ans);
    }
    return 0;
}