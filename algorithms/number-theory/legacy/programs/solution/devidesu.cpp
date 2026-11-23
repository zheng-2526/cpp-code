// 题意或用途（据代码整理）：把正整数写成质因数的乘积。
// 阅读要点：从 2 开始试除，同一因子能除尽多次就反复输出，直到余下的数处理完。

#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;
    cout << n << '=';
    for(int i = 2; i <= n; i++){
        while(n % i == 0) {
            if(n != i) {
                cout << i << '*';
            } else {
                cout << i;
            }
            n /= i;
        }
    }
    return 0;
}