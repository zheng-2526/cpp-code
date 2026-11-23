// 题意或用途（据代码整理）：读取一列数据与若干位置查询，按一基下标输出对应元素。
// 阅读要点：数组随机访问让每次查询只需一步。程序使用 z0.in/out，输入位置必须合法。

#include <bits/stdc++.h>
using namespace std;

int a[2000006], n, m, x;

int main() {
    freopen("z0.in","r",stdin);
    freopen("z0.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }
    return 0;
}