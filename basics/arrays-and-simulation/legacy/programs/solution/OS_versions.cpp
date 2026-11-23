// 题意或用途（据代码整理）：比较 Lynx、Serval、Ocelot 三个版本的相对顺序，判断第一个是否不早于第二个。
// 阅读要点：把 Ocelot 当作最高版本，分别列出同版本和跨版本条件。

#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    cin >> s1 >> s2;
    if(s1 == "Ocelot") {
        if(s2 == "Ocelot") {
            printf("Yes");
            return 0;
        }
        else {
            printf("No");
            return 0;
        }
    }
    if(s1 == "Serval") {
        if(s2 == "Lynx") {
            printf("No");
            return 0;
        }
        else {
            printf("Yes");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}