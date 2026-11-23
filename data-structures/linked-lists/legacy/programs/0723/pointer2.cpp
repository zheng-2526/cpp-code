// 题意或用途（据代码整理）：维护单链表，支持在编号 x 之后插入 y、查询 x 的后继、删除 x 的后继。
// 阅读要点：节点预先按编号存入数组。插入先接上原后继再改 x 的指针；删除时跨过后继。
// 注意：删除分支假定后继存在，传入空后继会解引用空指针。

#include <bits/stdc++.h>
using namespace std;

int k, x, y;

struct nod{
    int x;
    nod *nex;
    nod() {
        nex = NULL;
    }
} s[1000005];

int main() {
    for(int i = 0; i < 1000005; i++) {
        s[i].x = i;
    }
    int n;
    s[1].x = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        if(k == 1) {
            cin >> x >> y;
            // 先保留 x 原来的后继，否则覆盖后无法把链表剩余部分接回。
            s[y].nex = s[x].nex;
            s[x].nex = &s[y]; // Insert node y after node x
        }
        else if(k == 2) {
            cin >> x;
            if(s[x].nex != NULL) {
                cout << (*s[x].nex).x << endl; // Output the value of the next node
            } else {
                cout << 0 << endl; // If there is no next node, output 0
            }
        }
        else if(k == 3) {
            cin >> x;
            s[x].nex = (*s[x].nex).nex; // Remove the next node
        }
    }
}