// 题目（同目录 statement_18278.pdf）：支持反转单个括号，并查询指定区间内最长合法连续括号串的长度。
// 阅读要点：栈存尚未配对的左括号下标，last_bad 标记最近未匹配的右括号。当前匹配段的长度由栈顶或 last_bad 确定。
// 注意：每次查询重新扫描区间，是线性查询版本。

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
                // 合法后缀不能跨过尚未匹配的左括号，也不能跨过最近失配的右括号。
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
