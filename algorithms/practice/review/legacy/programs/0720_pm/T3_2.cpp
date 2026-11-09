#include<bits/stdc++.h>
#define int long long//记得开 long long。
using namespace std;
const int mod=998244353;
bool a[1005][1005];
int cntn[1005][1005];
int mxm[1005][1005];
int mxn[1005][1005];
signed main(){
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--){
		memset(cntn,0,sizeof(cntn));
		memset(mxn,0,sizeof(mxn));
		memset(mxm,0,sizeof(mxm));
		int n,m,c,f;
		int ansc=0,ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				a[i][j]=c-'0';
			}
		}
		
		if(c==0&&f==0){//特判。
			printf("0 0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cntn[i][j]=cntn[i-1][j]+a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(!a[i][j]){
					mxm[i][j]=max(j,mxm[i][j+1]);
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=n;i>=1;i--){
				if(!a[i][j]){
					mxn[i][j]=max(i,mxn[i+1][j]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=n;i++){
				if(a[i][k]) continue;
				for(int j=i+2;j<=n;j++){
					if(a[j][k]) break;
					int cnt1=0,cnt2=0,cnt3=0;
					if(cntn[j][k]-cntn[i][k]==0){
						cnt1=mxm[i][k]-k;//a(i,k)的方案数。
						cnt2=mxm[j][k]-k;//a(j,k)的方案数。
					}
					cnt3=mxn[j][k]-j;//a(j,k)这个点能再向下取到的
					int p=cnt1*cnt2;//乘法原理，两个方案数相乘。
					p%=mod;
					ansc=(ansc+p)%mod;//C的方案数。
					ansf=(ansf+p*cnt3)%mod;//F的方案数
				}
			}
		}
		printf("%lld ",ansc%mod);
		if(f==0) printf("0\n");
		else printf("%lld\n",ansf%mod);
	}
	return 0;
}

