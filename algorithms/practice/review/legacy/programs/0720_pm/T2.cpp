#include<bits/stdc++.h>
#define afor(x,y,z) for(int x=y;x<=z;x++)
#define bfor(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
typedef long long ll;
typedef const int cint;
cint N=3010;
struct rec{
	char a,b;//每个字符串的最大最小值
} a[N];
int n,m;
char s[N][N];
int main() {
	scanf("%d%d",&n,&m);
	afor(i,1,n) {
		a[i].a=123,a[i].b=96;
		scanf("%s",s[i]+1);
		afor(j,1,m) {//处理最大最小值
			a[i].a=min(a[i].a,s[i][j]);
			a[i].b=max(a[i].b,s[i][j]);
		}
	}
	afor(i,1,n) {
		bool ans=1;
		afor(j,1,n) if(j!=i&&a[i].a>=a[j].b) ans=0;
		//如果有别的串的最小值大于等于当前串的最大值，那么当前串的字典序不可能最小
		printf("%d",ans);
	}
	return 0;
}
/*
由于可以交换任意两个字符且不限次数，所以可以得到当前字符串的任意一种排列。
那么只需要使当前串达到字典序最小的状态（升序排列），其他字符串均达到字典序最大的状态（降序排列），再进行比较即可。
可以先处理出每个字符串的最小值和最大值，如果当前串的最小值比其他每个字符串的最大值都要小，
那么可以将其他字符串的最大值都放在串首，将当前串的最小值放在串首，这样就可以使当前串的字典序最小了。
*/