#include <bits/stdc++.h>
using namespace std;

string m, l;

void chan(int mL, int mR, int pL, int pR) {
    if (mL > mR || pL > pR) return;
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