// 题意或用途（据代码整理）：读取小写字母标记的二叉树，星号表示空孩子，输出前序遍历。
// 阅读要点：先把字符映射为数组下标，再按根、左、右递归。现有代码把 a 固定当作根。

#include <bits/stdc++.h>
using namespace std;

int a[27][3], n;
char c;

void dfs(int no) {
    cout << char(no + 'a' - 1);
    if(a[no][1]) {
        dfs(a[no][1]);
    }
    if(a[no][2]) {
        dfs(a[no][2]);
    }
}

int main() {
    cin >> n;
    int x;
    getchar();
    for(int i = 1; i <= n; i++) {
        c = getchar();
        x = int (c - 'a') + 1;
        c = getchar();
        if(c != '*')
            a[x][1] = int(c - 'a') + 1;
        else
            a[x][1] = 0;
        c = getchar();
        if(c != '*')
            a[x][2] = int(c - 'a') + 1;
        else
            a[x][2] = 0;
        getchar();
    }
    dfs(1);
    return 0;
}