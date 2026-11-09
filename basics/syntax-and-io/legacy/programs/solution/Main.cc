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