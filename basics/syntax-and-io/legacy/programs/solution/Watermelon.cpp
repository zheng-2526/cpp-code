#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    if(a > 2 && !(a & 1)) printf("YES");
    else printf("NO");
    return 0;
}