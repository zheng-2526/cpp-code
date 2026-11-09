#include <bits/stdc++.h>
using namespace std;

static const int KEEP = 80;

vector<int> phi_value, spf;

long long phi_product(int a, int b) {
    long long ans = 1LL * phi_value[a] * phi_value[b];
    int g = std::gcd(a, b);
    int last = 0;
    while (g > 1) {
        int p = spf[g];
        if (p != last) {
            ans = ans / (p - 1) * p;
            last = p;
        }
        while (g % p == 0) g /= p;
    }
    return ans;
}

vector<int> merge_top(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    c.reserve(KEEP);
    int i = 0, j = 0;
    while ((i < (int)a.size() || j < (int)b.size()) && (int)c.size() < KEEP) {
        int take;
        if (j == (int)b.size() || (i < (int)a.size() && a[i] > b[j])) {
            take = a[i++];
        } else if (i == (int)a.size() || b[j] > a[i]) {
            take = b[j++];
        } else {
            take = a[i];
            ++i; ++j;
        }
        if (c.empty() || c.back() != take) c.push_back(take);
    }
    return c;
}

struct SegTree {
    int n;
    vector<vector<int>> tree;
    SegTree(const vector<int> &p) {
        int sz = (int)p.size() - 1;
        n = 1;
        while (n < sz) n <<= 1;
        tree.assign(2 * n, {});
        for (int i = 1; i <= sz; ++i) tree[n + i - 1] = {p[i]};
        for (int i = n - 1; i >= 1; --i) tree[i] = merge_top(tree[i << 1], tree[i << 1 | 1]);
    }
    vector<int> query(int l, int r) const {
        vector<int> left, right;
        l += n - 1;
        r += n - 1;
        while (l <= r) {
            if (l & 1) left = merge_top(left, tree[l++]);
            if (!(r & 1)) right = merge_top(tree[r--], right);
            l >>= 1;
            r >>= 1;
        }
        return merge_top(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    spf.resize(n + 1);
    phi_value.resize(n + 1);
    for (int i = 0; i <= n; ++i) phi_value[i] = i;
    for (int i = 2; i <= n; ++i) {
        if (!spf[i]) {
            for (long long j = i; j <= n; j += i) {
                if (!spf[j]) spf[j] = i;
                phi_value[j] = phi_value[j] / i * (i - 1);
            }
        }
    }
    if (n >= 1) {
        spf[1] = 1;
        phi_value[1] = 1;
    }

    SegTree seg(p);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        vector<int> cand = seg.query(l, r);
        long long best = 0;
        for (int i = 0; i < (int)cand.size(); ++i) {
            if (i > 0 && 1LL * cand[i] * cand[0] <= best) break;
            for (int j = i + 1; j < (int)cand.size(); ++j) {
                if (1LL * cand[i] * cand[j] <= best) break;
                best = max(best, phi_product(cand[i], cand[j]));
            }
        }
        cout << best << '\n';
    }
    return 0;
}
