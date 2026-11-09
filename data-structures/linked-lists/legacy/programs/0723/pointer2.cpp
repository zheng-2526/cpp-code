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