#include<bits/stdc++.h>
using namespace std;
int n,dp[5050];
struct Node{
	int x,y;
}node[10000];
bool compare(struct Node a,struct Node b){
	if(a.x==b.x) return a.y>b.y;
	return a.x>b.x;
}
int main(){
	int maxx=-1;cin>>n;
	for(int i=1;i<=n;i++) cin>>node[i].x>>node[i].y;
	sort(node+1,node+n+1,compare);
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++)
		if(node[j].y<node[i].y) dp[i]=max(dp[i],dp[j]+1);
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx<<endl;
	return 0;
}
