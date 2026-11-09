#include <bits/stdc++.h>
using namespace std;

int n, l, r, x, p;
char s[10005], ss[15];

int main() {
    cin >> n >> s;
    cout << s;
    // while(n--) {
    //     cin >> x;
    //     if(x == 1) {
    //         int flag1 = 0;
    //         cin >> ss;
    //         int xx;
    //         for(xx = 0; xx < s.size(); xx++) {
    //             if(flag1 >= 3) break;
    //             bool flag = true;
    //             for(int j = 0; j < ss.size(); j++) {
    //                 if(s[xx + j] != ss[j]) {
    //                     flag = false;
    //                     break;
    //                 }
    //             }
    //             if(flag) {
    //                 flag1++;
    //                 cout << xx;
    //                 break;
    //             }
    //         }
    //         for(int i = xx + 1; i < s.size(); i++) {
    //             if(flag1 >= 3) break;
    //             bool flag = true;
    //             for(int j = 0; j < ss.size(); j++) {
    //                 if(s[i + j] != ss[j]) {
    //                     flag = false;
    //                     break;
    //                 }
    //             }
    //             if(flag) {
    //                 flag1++;
    //                 cout << ' ' << i;
    //             }
    //         }
    //         if(!flag1) cout << -1;
    //         cout << '\n';
    //     }
    //     if(x == 3) {
    //         cin >> l >> r;
    //         for(int i = l; i <= (l + r) / 2; i++) {
    //             swap(s[i], s[r - (i - l)]);
    //         }
    //     }
    // }
}