#include <bits/stdc++.h>
using namespace std;

int T,id;
int n,m,c,f,vc,vf;
bool a[1001][1001];
char xx;

void schc(int x,int y) {
	for(int k=y+1;k<=m;k++) {
		if(a[x][k]) break;
		for(int i=x+1;i<n;i++) {
			if(a[i][y]||a[i+1][y]) break;
			for(int j=y+1;j<=m;j++) {
				if(a[i+1][j]) break;
				else vc++;
			}
		}
	}
}

void schf(int x,int y) {
	for(int k=y+1;k<=m;k++) {
		if(a[x][k]) break;
		for(int i=x+1;i<=n-2;i++) {
			if(a[i][y]||a[i+1][y]) break;
			else {
				for(int h=i+2;h<=n;h++){
					if(a[h][y]) break;
					for(int j=y+1;j<=m;j++) {
						if(a[i+1][j]) break;
						else vf++;
					}
				}
				vf%=998244353;
			}
		}
	}
}

int main() {
//	freopen("plant.in","r",stdin);
//	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--) {
		vc=0,vf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0) {
			printf("0\n");
			continue;
		}
		getchar();
		c%=998244353,f%=998244353;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++){
				scanf("%c",&xx);
				a[i][j]=(int)(xx-'0');
			}
			getchar();
		}
//		for(int i=1;i<=n;i++) 
//		{
//			for(int j=1;j<=m;j++)
//				printf("%d ",a[i][j]);
//			printf("\n");
//		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(!a[i][j]) schc(i,j),schf(i,j);
			}
		}
		printf("%d %d\n",(vc*c)%998244353,(vf*f)%998244353);
	}
    return 0;
}