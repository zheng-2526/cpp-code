#include <bits/stdc++.h>
using namespace std;

int n, q;
char s[30];

void qsort(int l, int r) {
    if(l >= r) return;
    int i = l, j = r;
    char mid = s[(l + r) >> 1];
    while(i <= j) {
        while(i <= r) {
            if(s[i] == mid) {
                i++;
                continue;
            }
            char c;
            cout << "? " << s[i] << ' ' << mid << '\n';
            cin >> c;
            if(c == '>') break;
            i++;
        }
        while(j >= l) {
            if(s[j] == mid) {
                j--;
                continue;
            }
            char c;
            cout << "? " << mid << ' ' << s[j] << '\n';
            cin >> c;
            if(c == '>') break;
            j--;
        }
        if(i <= j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }
    if(l < j) qsort(l, j);
    if(i < r) qsort(i, r);
}
 
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) s[i] = 'A' + i - 1;
    qsort(1, n);
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << s[i];
}