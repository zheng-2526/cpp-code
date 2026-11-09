#include <bits/stdc++.h>
using namespace std;

int longest_valid(const string &s, int l, int r) {
    vector<int> st;
    int last_bad = l - 1;
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {
            if (st.empty()) {
                last_bad = i;
            } else {
                st.pop_back();
                int left = st.empty() ? last_bad : st.back();
                ans = max(ans, i - left);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k;
            cin >> k;
            s[k] = (s[k] == '(' ? ')' : '(');
        } else {
            int l, r;
            cin >> l >> r;
            cout << longest_valid(s, l, r) << '\n';
        }
    }
    return 0;
}
