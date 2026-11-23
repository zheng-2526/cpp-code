// 题意或用途（据代码整理）：对每个整数判断能否平分成两个相同整数，可以时输出两个一半。
// 阅读要点：最低位为 1 表示奇数，否则整数平分。

#include <bits/stdc++.h>
using namespace std;
 
long long n, T;
 
int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n & 1) printf("No\n");
        else printf("Yes\n%lld %lld\n", n / 2, n / 2);
    }
    return 0;
}