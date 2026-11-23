// 题目（同目录 statement_18282.pdf）：给定一组按顺序执行的模乘赋值和若干查询，求每组初值执行 k 轮后的结果。
// 阅读要点：把连乘拆成初始变量的幂，指数用矩阵倍增，另外用布尔矩阵跟踪实际存在的因子。
// 注意：指数取模后可能变为 0，pos 可以区分这一情况与该因子从未出现，避免把含零的乘积算错。

#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int PHI = MOD - 1;

using Mat = vector<vector<int>>;
using BMat = vector<bitset<200>>;

long long mod_pow(long long a, int e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

Mat mul_mod(const Mat &a, const Mat &b, int n) {
    Mat c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (!a[i][k]) continue;
            long long aik = a[i][k];
            for (int j = 0; j < n; ++j) {
                c[i][j] = (c[i][j] + aik * b[k][j]) % PHI;
            }
        }
    }
    return c;
}

BMat mul_bool(const BMat &a, const BMat &b, int n) {
    BMat bt(n), c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j]) bt[j].set(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((a[i] & bt[j]).any()) c[i].set(j);
        }
    }
    return c;
}

vector<int> apply_map(const vector<int> &val, const Mat &e, const BMat &pos, int n) {
    vector<array<int, 31>> pw(n);
    for (int j = 0; j < n; ++j) {
        long long cur = val[j];
        for (int b = 0; b < 31; ++b) {
            pw[j][b] = (int)cur;
            cur = cur * cur % MOD;
        }
    }

    vector<int> nxt(n, 1);
    for (int i = 0; i < n; ++i) {
        bool zero = false;
        long long prod = 1;
        for (int j = 0; j < n; ++j) {
            // 先问因子是否实际出现，再看指数余数。零底数不能只按指数余数判断。
            if (!pos[i][j]) continue;
            if (val[j] == 0) {
                zero = true;
                break;
            }
            int exp = e[i][j];
            int bit = 0;
            while (exp) {
                if (exp & 1) prod = prod * pw[j][bit] % MOD;
                exp >>= 1;
                ++bit;
            }
        }
        nxt[i] = zero ? 0 : (int)prod;
    }
    return nxt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    Mat trans(n, vector<int>(n));
    BMat pos(n);
    for (int i = 0; i < n; ++i) {
        trans[i][i] = 1;
        pos[i].set(i);
    }

    for (int i = 0; i < m; ++i) {
        int x, u, v;
        cin >> x >> u >> v;
        --x; --u; --v;
        for (int j = 0; j < n; ++j) {
            // 两数相乘时，同一初始变量的指数相加，结果覆盖当前赋值的目标行。
            trans[x][j] = trans[u][j] + trans[v][j];
            if (trans[x][j] >= PHI) trans[x][j] -= PHI;
        }
        pos[x] = pos[u] | pos[v];
    }

    const int LOG = 20;
    vector<Mat> pw(LOG);
    vector<BMat> bpw(LOG);
    pw[0] = trans;
    bpw[0] = pos;
    for (int b = 1; b < LOG; ++b) {
        // 每次把已有变换与自己复合，得到多执行一倍轮数的变换。
        pw[b] = mul_mod(pw[b - 1], pw[b - 1], n);
        bpw[b] = mul_bool(bpw[b - 1], bpw[b - 1], n);
    }

    while (q--) {
        int k;
        cin >> k;
        vector<int> val(n);
        for (int i = 0; i < n; ++i) cin >> val[i];
        for (int b = 0; b < LOG; ++b) {
            if (k & (1 << b)) val = apply_map(val, pw[b], bpw[b], n);
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << val[i];
        }
        cout << '\n';
    }
    return 0;
}
