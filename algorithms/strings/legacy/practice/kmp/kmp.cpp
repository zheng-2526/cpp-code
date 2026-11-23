// 题意或用途（据代码整理）：在文本 b 中查找模式 a，输出各匹配位置及模式的前缀表。
// 阅读要点：nex[j] 是前 j 个字符中最长的相等真前后缀长度；失配时保留这个仍可能匹配的部分。
// 注意：历史代码对单字符模式、匹配后的回退与末尾访问需额外检查，别直接当作通用 KMP 模板。

#include <bits/stdc++.h>
using namespace std;

string a, b;
int nex[1000005];

void build_nex() {
    int i = 1, j = 0;
    while(1) {
        if(a[i + 1] == a[j + 1]) {
            nex[i + 1] = j + 1;
            i++, j++;
        }
        else {
            if(j == 0) i++;
            // 失配后回到可复用的最长前后缀，文本扫描位置不回退。
            else j = nex[j];
        }
        if(i == a.size() - 1) break;
    }
    return;
}

int main() {
    cin>>b>>a;
    a = " " + a, b = " " + b;
    build_nex();
    int i = 0, j = 0;
    while(i < b.size()) {
        if(b[i + 1] == a[j + 1]) {
            j++, i++;
        }
        else {
            if(j == 0) i++;
            else j = nex[j];
        }
        if(j == a.size() - 1) {
            printf("%d\n", i - j + 1);
        }
    }
    for(int i = 1; i <= a.size() - 1; i++) printf("%d ", nex[i]);
    return 0;
}
