// 题意或用途（据代码整理）：对比两个字符串中互为倒序的相邻字符对，每命中一次把结果翻倍。
// 阅读要点：双层循环逐对比字符，代码以第一串长度约束两次扫描，原题计数含义未确认。

#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int ans = 1;

int main() {
    cin>>s1 >> s2;
    int len = s1.length();
    for(int i = 0; i < len-1; i++) {
        for(int j = 1; j < len; j++) {
            if(s1[i] == s2[j] && s1[i + 1] == s2[j - 1]) {
                ans *= 2;
            }
        }
    }
    cout<< ans;
    return 0;
}