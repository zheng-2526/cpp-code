// 题意或用途（据代码整理）：将 A 进制的非负数转换为 B 进制，数字可用 0 至 9 和 A 至 F 表示。
// 阅读要点：先把每一位按 A 的幂累加为整数，再反复除 B 取余，从末尾倒着输出。
// 注意：使用 int 和浮点 pow，且输入值为 0 时不打印数字。

#include <bits/stdc++.h>
using namespace std;

int A, B, ans;
string s;
char a[100];

int main() {
    cin >> A;
    getchar();
    getline(cin, s);
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] >= '1' && s[i] <= '9') {
            ans += pow(A, s.size() - 1 - i) * (s[i] - '0');
        }
        if(s[i] >= 'A' && s[i] <= 'F') {
            ans += pow(A, s.size() - 1 - i) * (s[i] - 'A' + 10);
        }
    }
    cin >> B;
    int i;
    for(i = 0; ans != 0; i++) {
        // 除以新底数的余数从最低位开始产生，最后逆序输出。
        int k = ans % B;
        ans /= B;
        if(k < 10) {
            a[i] = k + '0';
        } else {
            a[i] = k - 10 + 'A';
        }
    }
    for(int j = i - 1; j >= 0; j--) {
        cout << a[j];
    }
    return 0;
}