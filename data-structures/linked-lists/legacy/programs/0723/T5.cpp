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