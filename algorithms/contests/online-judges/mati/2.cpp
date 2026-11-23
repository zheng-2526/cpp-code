// 题意或用途（据代码整理）：给出待统计字符串和若干查询词，对每个字符串统计多少个查询词是它的前缀。
// 阅读要点：逐字符比较每一对的开头。代码没有先检查查询词是否更长，学习时要留意字符串边界。

#include<bits/stdc++.h> 
using namespace std;

string s[1010], x;
int n, m, num[1010];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= m; i++) {
        cin >> x;
        for(int k = 1; k <= n; k++){
            bool flag = 1;
            for(int j = 0; j < x.size(); j++) {
                if(s[k][j] != x[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) num[k]++;
        }
    }
    for(int i = 1;i <= n; i++) cout << num[i] << ' ';
    return 0;
}