#include <bits/stdc++.h>
using namespace std;

double s;

int main() {
    cin >> s;
    unsigned long long* bits = (unsigned long long*)&s;
    printf("64bits IEEE 754: %s\n", bitset<64>(*bits).to_string().c_str());

    unsigned long long n = *bits;
    int sign = (n >> 63) & 1;
    int exponent = (n >> 52) & 0x7FF;  // 11位指数
    unsigned long long mantissa = n & 0xFFFFFFFFFFFFF;  // 52位尾数
    
    printf("+-: %d\n", sign);
    printf("zhi: 0x%03X (pian: %d)\n", exponent, exponent - 1023);
    printf("wei: 0x%013llX\n", mantissa);
    return 0;
}