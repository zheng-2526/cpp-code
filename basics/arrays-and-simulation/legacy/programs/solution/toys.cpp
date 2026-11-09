#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 1;

struct node{
    string nam;
    bool dire;
}a[100005];

struct que{
    bool dire;
    int num;
}b[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].dire >> a[i].nam;
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i].dire >> b[i].num;
        if((!a[ans].dire && b[i].dire) || (a[ans].dire && !b[i].dire)) {
            ans += b[i].num;
        }
        else {
            ans -= b[i].num;
        }
        while(ans <= 0) {
            ans += n;
        }
        while(ans > n) {
            ans -= n;
        }
    }
    cout << a[ans].nam;
    return 0;
}