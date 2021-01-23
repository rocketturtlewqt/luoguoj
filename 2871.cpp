#include<bits/stdc++.h>
using namespace std;
int n,m,dp[20000];
struct Node{
	int w,v;
}node[20000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>node[i].w>>node[i].v;
	for(int i=1;i<=n;i++)
	for(int j=m;j>=node[i].w;j--)
	dp[j]=max(dp[j],dp[j-node[i].w]+node[i].v);
	cout<<dp[m]<<endl;
	return 0;
}
