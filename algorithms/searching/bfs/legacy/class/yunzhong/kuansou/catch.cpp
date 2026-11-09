#include <bits/stdc++.h>
using namespace std;

int n, k;
bool a[1000005];
queue<pair<int, int>> q;

int main() {
    scanf("%d%d", &n, &k);
    if(n >= k) {
        printf("%d", n - k);
        return 0;
    }
    q.push({n, 0});
    while(!q.empty()){
        pair<int, int> t = q.front();
        q.pop();
        if(!a[t.first + 1] && t.first + 1 <= 100000) {
            if(t.first + 1 == k) {
                printf("%d", t.second + 1);
                return 0;
            }
            a[t.first + 1] = true;
            q.push({t.first + 1, t.second + 1});
        }
        if(!a[t.first - 1] && t.first - 1 >= 0) {
            if(t.first - 1 == k) {
                printf("%d", t.second + 1);
                return 0;
            }
            a[t.first - 1] = true;
            q.push({t.first - 1, t.second + 1});
        }
        if(!a[t.first * 2] && t.first * 2 <= 200000) {
            if(t.first * 2 == k) {
                printf("%d", t.second + 1);
                return 0;
            }
            a[t.first * 2] = true;
            q.push({t.first * 2, t.second + 1});
        }
    }
    return 0;
}