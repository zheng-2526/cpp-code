#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
priority_queue<int,vector<int>,greater<int> > q,t1,t2;//t1，t2分别存储清洗和水煮任务的完成时间
int main(){
	cin>>n>>m>>a>>b;
	for(int i=0;i<m;i++) q.push(0);//初始可用时间为0
	int cnt1=0,cnt2=0;
	while(cnt1<n||cnt2<n){//循环分配任务
		if(q.empty()) break;//没有可用机器人
		int time=q.top();
		q.pop();
		if(cnt1<n){
			t1.push(time+a);
			q.push(time+a);
			cnt1++;
		}
		else if(cnt2<n){
			if(t1.empty()) break;//没有已经清洗好的青菜就不能开始水煮
			int st=max(time,t1.top());
			t1.pop();
			t2.push(st+b);
			q.push(st+b);
			cnt2++;
		}
		else continue;
	}
	int ans=0;
	while(!t2.empty()){//寻找最后一个水煮任务的完成时间
		ans=t2.top();
		t2.pop();
	}
	cout<<ans;
    return 0;
}