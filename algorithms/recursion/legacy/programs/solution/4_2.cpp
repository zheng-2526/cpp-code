#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long AB = 0, AC = 0, BA = 0, BC = 0, CA = 0, CB = 0;

    for (int i = 1; i <= n; i++) {
        long long oldAB = AB, oldAC = AC, oldBA = BA;
        long long oldBC = BC, oldCA = CA, oldCB = CB;

        // 直接允许的方向
        AB = oldAC + 1 + oldCB; // A -> B，中转柱是 C
        BC = oldBA + 1 + oldAC; // B -> C，中转柱是 A
        CA = oldCB + 1 + oldBA; // C -> A，中转柱是 B

        // 不允许直接移动的方向，需要绕一下
        AC = oldAC + 1 + oldCA + 1 + oldAC; // A -> B -> C
        BA = oldBA + 1 + oldAB + 1 + oldBA; // B -> C -> A
        CB = oldCB + 1 + oldBC + 1 + oldCB; // C -> A -> B
    }

    cout << AC << endl;

    return 0;
}