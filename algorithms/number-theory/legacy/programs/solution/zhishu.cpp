#include <bits/stdc++.h>
using namespace std;

long long a;

bool isZhishu(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> a;
    printf("%s\n", isZhishu(a) ? "YES" : "NO");
}