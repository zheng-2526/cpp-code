#include<bits/stdc++.h>
using namespace std;

int n, m, ans = 1;

struct node{
    bool dire;
    string name;
} a[100005];

struct ques{
    bool dire;
    int num;
}b[100005];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].dire >> a[i].name;
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i].dire >> b[i].num;
        if(b[i].dire == 1) {
            if(a[ans].dire == 0) ans += b[i].num;
            else ans -= b[i].num;
            if(ans > n) ans -= n;
            else if(ans <= 0) ans += n;
        }
        else {
            if(a[ans].dire == 1) ans += b[i].num;
            else ans -= b[i].num;
            if(ans > n) ans -= n;
            else if(ans <= 0) ans += n;
        }
    }
    cout << a[ans].name;
}
