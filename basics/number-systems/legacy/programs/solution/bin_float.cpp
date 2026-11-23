// 题意或用途（据代码整理）：观察 double 在常见 IEEE 754 二进制表示中的符号位、指数和尾数字段。
// 阅读要点：通过移位与掩码提取 1、11、52 位字段。
// 注意：历史写法用不兼容的指针类型读取 double，违反严格别名规则。特殊值和次正规数的含义也不能只用偏置相减解释。

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