// 题意或用途（据代码整理）：人物围成一圈且各有面向，执行相对左右移动后输出停留位置的名字。
// 阅读要点：命令方向和人物面向共同决定下标加减，越过首尾时绕回圆环。单次只修正一圈，依赖步数范围。

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
