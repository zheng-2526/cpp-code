// 题意或用途（据代码整理）：给定二叉树的中序和前序遍历，输出后序遍历，假定节点值唯一。
// 阅读要点：前序首项是根，中序中的根划分左右子树。先处理两段再输出根。

#include <bits/stdc++.h>
using namespace std;

string m, f;

void build(int inL, int inR, int preL, int preR) {
    if (inL > inR || preL > preR) return;
    char root = f[preL];
    int k = m.find(root, inL);
    int Lsize = k - inL;
    build(inL, k - 1, preL + 1, preL + Lsize);
    build(k + 1, inR, preL + Lsize + 1, preR);
    // 后序的根放在左右子树之后，所以在两次递归返回后再输出。
    cout << root;
}

int main() {
    cin >> m >> f;
    build(0, m.size() - 1, 0, f.size() - 1);
    return 0;
}