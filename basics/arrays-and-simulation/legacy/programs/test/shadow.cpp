#include <bits/stdc++.h>
using namespace std;

double x, y, ans;

int main() {
    scanf("%lf%lf", &x, &y);
    ans = x / (y * y);
    ans > 25 ? printf("%.1lf\nPANG", ans) : printf("%.1lf\nHai Xing", ans);
    return 0;
}