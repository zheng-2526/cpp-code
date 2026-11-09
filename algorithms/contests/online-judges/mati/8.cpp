#include<bits/stdc++.h> 
using namespace std;

long long n, m, a[1000006], l, num[1000006], x, ans;

int main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while(m--){
        for(int i = 1; i <= 1000000; i++) num[i] = 0;
        x = ans = 0;
        scanf("%lld", &l);
        // cout << '\n';
        for(int i = 1; i <= l; i++) {
            if(!num[a[i]]) x++;
            num[a[i]] ++;
        }
        ans += x;
        // cout << x << '\n';
        for(int i = l + 1; i <= n; i++) {
            if(!num[a[i]]) x++;
            if(num[a[i - l - 1]] == 1) x--;
            num[a[i]] += 1;
            num[a[i - l - 1]] -= 1;
            ans += x;
            // cout << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << x << '\n';
        }
        printf("%lld\n", ans);
    }
    return 0;
}