#include <bits/stdc++.h>
using namespace std;

string s;
int n, ans1, ans2;
bool flag;

int main() {
    while(getline(cin, s)) {
        if(s == ".") break;
        n++;
        if(s.find("chi1 huo3 guo1") != string::npos) {
            if(!flag) {
                flag = 1;
                ans1 = n;
            }
            ans2++;
        }
    }
    printf("%d\n", n);
    if(flag) {
        printf("%d %d", ans1, ans2);
    }
    else printf("-_-#");
    return 0;
}