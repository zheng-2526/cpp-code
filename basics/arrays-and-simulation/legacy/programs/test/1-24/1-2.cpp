#include <bits/stdc++.h>
using namespace std;

double rp, rd, ans;
bool s;

int main() {
    scanf("%lf%d%lf", &rp, &s, &rd);
    ans = rp * (s ? 1.26 : 2.455);
    printf("%.2lf ", ans);
    if(ans > rd) printf("T_T");
    else printf("^_^");
    return 0;
}