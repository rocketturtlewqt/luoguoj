#include<bits/stdc++.h>
using namespace std;
int n,m,dp[1000000],value[1000000];
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>value[i];
	for(int i=1;i<=n;i++)
	for(int j=m;j>=value[i];j--)
	dp[j]=max(dp[j],dp[j-value[i]]+value[i]);
	cout<<dp[m]<<endl;
	return 0;
}
