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