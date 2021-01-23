#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxium 501
#define inf 99999999
using namespace std;
int n,m;
int dp[maxium][101][101];//dp[i][j][k]表示前i个字符，有j个j变成了z，有k个z变成了j 
char s[maxium];
void start()
{
	cin>>n>>m;
	scanf("%s",s+1);
} 
void solve()
{
	memset(dp,128,sizeof(dp));
	dp[0][0][0]=dp[1][0][0]=0;
	if(s[1]=='j') dp[1][1][0]=0;
	else if(s[1]=='z') dp[1][0][1]=0;
	for(int i=2;i<=n;i++)
	for(int j=0;j<=m;j++)
	for(int k=0;k<=m;k++)
	{
		dp[i][j][k]=dp[i-1][j][k];
		if(s[i]=='z'&&s[i-1]=='j') dp[i][j][k]=max(dp[i][j][k],dp[i-2][j][k]+1);
		if(j&&s[i]=='j'&&s[i-1]=='j') dp[i][j][k]=max(dp[i][j][k],dp[i-2][j-1][k]+1);
		if(j&&k&&s[i]=='j'&&s[i-1]=='z') dp[i][j][k]=max(dp[i][j][k],dp[i-2][j-1][k-1]+1);
		if(k&&s[i]=='z'&&s[i-1]=='z') dp[i][j][k]=max(dp[i][j][k],dp[i-2][j][k-1]+1);
	}
	int ans=-inf;
	for(int i=0;i<=m;i++)
	ans=max(ans,dp[n][i][i]);
	cout<<ans;
}
int main()
{
	start();
	solve();
	return 0;
}
