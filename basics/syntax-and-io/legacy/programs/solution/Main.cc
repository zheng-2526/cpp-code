// 题意或用途（据代码整理）：将可平分的整数拆成两份相等的整数。
// 阅读要点：奇数无法整数平分，偶数输出两个 n/2。

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
	cin >> n;
	if(n%2) printf("No");
	else {
		printf("Yes\n%d %d", n/2, n/2);
	}
    return 0;
}