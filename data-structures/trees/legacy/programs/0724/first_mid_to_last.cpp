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
    cout << root;
}

int main() {
    cin >> m >> f;
    build(0, m.size() - 1, 0, f.size() - 1);
    return 0;
}