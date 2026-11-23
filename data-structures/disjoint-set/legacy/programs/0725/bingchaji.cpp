// 题意或用途（据代码整理）：给若干关系对，合并对应集合，再查询两元素是否同组。
// 阅读要点：fa 初始指向自己，find 沿父指针找根并压缩路径。
// 注意：第一行 scanf 的格式只有两个转换项，却传入三项地址，询问数 x 并未读入。

#include <bits/stdc++.h>
using namespace std;

int fa[200005], n, m, x, y, z;

int find(int x) {
    if (fa[x] == x) {
        return x;
    }
        else {
        int m = find(fa[x]);
        // 把沿途节点直接连向根，下一次查找会经过更短的链。
        fa[x] = m;
        return find(fa[x]);
    }
}

int main() {
    scanf("%d%d", &n, &m, &x);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> y >> z;
        fa[find(y)] = find(z);
    }
    for(int i = 1; i <= x; i++) {
        cin >> y >> z;
        if (find(y) == find(z)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}