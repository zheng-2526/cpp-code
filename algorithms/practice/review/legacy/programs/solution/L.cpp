#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    int k;
    cin >> x >> k;
    
    if (k == 1) {
        cout << x << " 1\n";
        return 0;
    }
    
    vector<pair<long long, int>> ans;
    
    long long cur = 1;
    long long sum = 0;
    for (int i = 1; i < k; i++) {
        ans.emplace_back(cur, 1);
        sum += cur;
        cur++;
    }
    
    long long last = x - sum;
    if (last > cur - 1) {
        ans.emplace_back(last, 1);
    } else {
        ans.back().first += 1;
        last = x - sum - 1 + (cur - 1);
        ans.emplace_back(last, 1);
    }
    
    for (auto &[n, m] : ans) {
        cout << n << " " << m << "\n";
    }
    
    return 0;
}