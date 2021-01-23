#include<bits/stdc++.h>
using namespace std;
int n,dp[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=2) dp[i]=dp[i-1]+dp[i-2];
		else dp[i]=dp[i-1];
	}
	cout<<dp[n]<<endl;
	return 0;
}
