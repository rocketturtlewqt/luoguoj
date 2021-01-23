#include<bits/stdc++.h>
using namespace std;
int n,dp[1050][1050],mat[1050][1050];
int main(){
	int maxx=-0x3f3f3f3f;cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) cin>>mat[i][j];
	dp[1][1]=mat[1][1];
	for(int i=1;i<=n-1;i++)
	for(int j=1;j<=i;j++){
		dp[i+1][j]=max(dp[i+1][j],dp[i][j]+mat[i+1][j]);
		dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+mat[i+1][j+1]);
	}
	for(int j=1;j<=n;j++) maxx=max(maxx,dp[n][j]);
	cout<<maxx<<endl;
}
