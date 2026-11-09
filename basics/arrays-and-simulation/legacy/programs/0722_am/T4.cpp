#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][55],x=1,y,k;
int main(){
	//可自行添加快读。
	cin>>n;
	m=n;
	while(k<n*n){//按照规律进行填充即可。
		while(y<m && k<n*n)a[x][++y]=++k;
		while(x<m && k<n*n)a[++x][y]=++k;
		while(y>n-m+1 && k<n*n)a[x][--y]=++k;
		while(x>n-m+2 && k<n*n)a[--x][y]=++k;
		if(k<n*n)a[x][++y]=++k;
		while(x<m-1 && k<n*n)a[++x][y]=++k;
		while(y<m-1 && k<n*n)a[x][++y]=++k;
		while(x>n-m+2 && k<n*n)a[--x][y]=++k;
		while(y>n-m+3 && k<n*n)a[x][--y]=++k;
		if(k<n*n)a[++x][y]=++k;
		m-=2;//本次循环填了2层。
	}for(int i=1;i<=n;i++){//输出方阵。
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;//好习惯。
}