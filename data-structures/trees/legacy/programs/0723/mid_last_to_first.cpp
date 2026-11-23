// 题意或用途（据代码整理）：给定二叉树中序、后序遍历，输出前序遍历，假定节点值唯一。
// 阅读要点：后序最后一项是根，从中序找到根后可按左子树长度切分两组区间。先输出根再递归。

#include <bits/stdc++.h>
using namespace std;

string m, l;

void chan(int mL, int mR, int pL, int pR) {
    if (mL > mR || pL > pR) return;
    // 后序总把根放在区间最后，左子树的规模决定两段在后序中的分界。
    char root = l[pR];
    cout << root;
    int k = m.find(root, mL);
    int lsize = k - mL;
    chan(mL, k - 1, pL, pL + lsize - 1);
    chan(k + 1, mR, pL + lsize, pR - 1);
}

int main() {
    getline(cin, m);
    getline(cin, l);
    chan(0, m.size() - 1, 0, l.size() - 1);
    cout << endl;
    return 0;
}