#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int a1[210], a2[210], ans[210];

int main() {
    getline(cin, s1);
    getline(cin, s2);
    char flag = '+';
    if(s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2) {
        swap(s1, s2);
        flag = '-';
    }
    for(int i = 0; i < s1.size(); i++) a1[i] = s1[s1.size() - i - 1] - '0';
    for(int i = 0; i < s2.size(); i++) a2[i] = s2[s2.size() - i - 1] - '0';
    for(int i = 0; i < s1.size(); i++) {
        if(a1[i] < a2[i]) {
            a1[i] += 10;
            a1[i + 1]--;
        }
        ans[i] = a1[i] - a2[i];
    }
    if(flag == '-') {
        cout << '-';
    }
    int index = 0;
    for(int i = s1.size() - 1; i >= 0; i--) {
        if(ans[i] != 0) {
            index = i;
            break;
        }
    }
    for(int i = index; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}