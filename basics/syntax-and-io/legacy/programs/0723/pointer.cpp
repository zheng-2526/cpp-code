// 题意或用途（据代码整理）：用 char 指针访问和修改同一个字符变量。
// 阅读要点：p 保存地址，解引用后读写原变量。直接 cout 输出 char* 会把它当作 C 字符串，这个示例未准备结尾空字符，不宜用它观察地址。

#include <bits/stdc++.h>
using namespace std;

int main() {
    char *p;
    char a = 97;
    p = &a; // Pointer p now points to the address of a
    cout << p << endl; // Output the address stored in p
    cout << *p << endl; // Output the value at the address stored in p (which is a)
    cout << a << endl; // Output the value of a
    a++;
    cout << *p << endl; // Output the updated value at the address stored in p (which is now a + 1)
    cout << a << endl; // Output the updated value of a
    (*p)++; // Increment the value at the address stored in p
    cout << *p << endl; // Output the value at the address stored in p after incrementing
    cout << a << endl; // Output the value of a after incrementing through p
    return 0;
}