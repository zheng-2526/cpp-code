// 题意或用途（据代码整理）：从十进制字符串删若干位，使留下的数尽量小。
// 阅读要点：贪心从左侧寻找相邻下降处，删除较大的前一位，最后略去多余前导零。
// 注意：这是数组模拟写法，末位哨兵和全零结果值得单独测试。

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