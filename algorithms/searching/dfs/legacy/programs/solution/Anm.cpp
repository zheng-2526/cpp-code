#include <bits/stdc++.h>
using namespace std;

int n, m, num[30];
bool a[30];

void Anm(int t, int x) {
    if(t == m + 1) {
        for(int i = 1; i <= m; i++) {
            printf("%3d", num[i]);
        }
        printf("\n");
        return;
    }
    for(int i = x + 1; i <= n - (m - t); i++) {
            num[t] = i;
            Anm(t + 1, i);
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    Anm(1, 0);
    return 0;
}