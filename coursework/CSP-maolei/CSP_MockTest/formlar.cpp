// 化学方程式配平：元素计数矩阵的秩小于物质数时，方程组存在非零解。
#include <bits/stdc++.h>
using namespace std;

const int N = 45;
const int primes[] = {
    1000000007, 1000000009, 1000000021, 1000000033,
    1000000087, 1000000093, 1000000097, 1000000103,
    1000000123, 1000000181, 1000000207, 1000000223
};
int n, m, t, a[N][N], b[N][N];
map<string, int> mp;

int qpow(long long x, int k, int p) {
    long long ans = 1;
    while(k) {
        if(k & 1) ans = ans * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return (int)ans;
}

bool fullRank(int p) {
    memcpy(b, a, sizeof a);
    for(int i = 1; i <= m; i++) {
        int pos = i;
        while(pos <= t && !b[pos][i]) pos++;
        if(pos > t) return false;
        swap(b[i], b[pos]);

        int inv = qpow(b[i][i], p - 2, p);
        for(int j = i + 1; j <= t; j++) {
            if(!b[j][i]) continue;
            long long k = 1LL * b[j][i] * inv % p;
            b[j][i] = 0;
            for(int l = i + 1; l <= m; l++) {
                b[j][l] -= k * b[i][l] % p;
                if(b[j][l] < 0) b[j][l] += p;
            }
        }
    }
    return true;
}

bool balance() {
    if(t < m) return true;
    // 由 Hadamard 不等式，行列式绝对值小于 (2^8.5)^40 = 2^340。
    // 这些素数的乘积大于 2^348。若它们都整除一个满列子式，该子式只能为零。
    for(int p : primes) {
        if(fullRank(p)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--) {
        cin >> m;
        mp.clear();
        t = 0;
        memset(a, 0, sizeof a);

        for(int i = 1; i <= m; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < (int)s.size();) {
                int st = j;
                while(j < (int)s.size() && s[j] >= 'a' && s[j] <= 'z') j++;
                int& id = mp[s.substr(st, j - st)];
                if(!id) id = ++t;

                int x = 0;
                while(j < (int)s.size() && s[j] >= '0' && s[j] <= '9') {
                    x = x * 10 + (s[j] - '0');
                    j++;
                }
                a[id][i] = x;
            }
        }
        cout << (balance() ? 'Y' : 'N') << '\n';
    }
    return 0;
}
