#include<bits/stdc++.h>
using namespace std;
int T,n,dp[1000000];
struct Node{
	int t,v;
}node[1000000];
int main(){
	cin>>T>>n;
	for(int i=1;i<=n;i++) cin>>node[i].t>>node[i].v;
	for(int i=1;i<=n;i++)
	for(int j=T;j>=node[i].t;j--)
	dp[j]=max(dp[j],dp[j-node[i].t]+node[i].v);
	cout<<dp[T]<<endl;
	return 0;
}
