// 题意或用途（据代码整理）：检查诗句两分句末尾是否都以 ong 押韵，满足就把末三个词换成 qiao ben zhong.。
// 阅读要点：先找逗号与句末标点，从末尾数空格定位替换起点。代码假定标点和词数符合题设。

#include <bits/stdc++.h>
using namespace std;

string s;
int n;
bool flag;

int main() {
    scanf("%d\n", &n);
    while(n--) {
        flag = 0;
        getline(cin, s);
        int x = s.find(',');
        if(s[x - 3] == 'o' && s[x - 2] == 'n' && s[x - 1] == 'g') {
            flag = 1;
        }
        x = s.size() - 1;
        if(flag) {
            if(s[x - 3] == 'o' && s[x - 2] == 'n' && s[x - 1] == 'g') {
                flag = 1;
            }
            else flag = 0;
        }
        if(flag) {
            for(int i = 1; i <= 3; i++) {
                while(s[--x] != ' ');
            }
            for(int i = 0; i <= x; i++) {
                printf("%c", s[i]);
            }
            printf("qiao ben zhong.\n");
        }
        else printf("Skipped\n");
    }
}