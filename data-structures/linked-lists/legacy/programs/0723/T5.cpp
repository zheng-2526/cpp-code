// 题意或用途（据代码整理）：带名字的人员排成圆环，按报数规则逐个删除并输出序号与姓名。
// 阅读要点：环形链表尾节点指回首节点，删除后直接连到被删节点的后继，用指针差得到原编号。
// 注意：结束条件比较姓名而非节点身份，同名会影响判断。

#include <bits/stdc++.h>
using namespace std;

int n, x;

struct Node {
    string name;
    Node* next;
    Node() {
        next = NULL;
    }
} nod[1005];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> nod[i].name;
        nod[i].next = &nod[(i + 1)]; // Circular linked list
    }
    nod[n].next = &nod[1]; // Last node points to the first node
    int i = 1, count = 1;
    while ((*nod[i].next).name != nod[i].name) {
        if((count + 1) % x == 0) {
            cout << nod[i].next - nod << ' ' << (*nod[i].next).name << endl; // Output the index and name of the node
            nod[i].next = (*nod[i].next).next; // Remove the next node
        }
        count++;
        i = nod[i].next - nod; // Move to the next node
    }
    cout << nod[i].next - nod << ' ' << (*nod[i].next).name << endl; // Output the last remaining node
    return 0;
}