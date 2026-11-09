#include<bits/stdc++.h>
using namespace std;

string st;
int n,a[1005],l,k;

int main()
{
    cin >> st;
    cin >> n;
    l = st.size();
    for(int i = 0; i < l; i++) a[i] = st[i] - '0';
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < l; j++)
            if(a[j] > a[j + 1]) {
                for(int k = j; k < l; k++) a[k] = a[k+1];
                l--;
                break;
            }
    int i = 0;
    while(a[i] == 0 && k < l - 1) {
        k++;
        i++;
    }
    for(int i = k; i < l; i++) cout << a[i];
    return 0;
}