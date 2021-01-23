#include<stdio.h>
#include<string.h>
#define maxium 31
int dp[maxium][maxium],n,m;
void start()
{
	scanf("%d%d",&n,&m);
}
void solve()
{
	dp[1][0]=1;
//	for(int i=1;i<=n;i++)
//	dp[i][0]=1;
	for(int j=1;j<=m;j++)
	for(int i=1;i<=n;i++)
	{
	    if(i==n) dp[n][j]=dp[n-1][j-1]+dp[1][j-1];
	    else if(i==1) dp[1][j]=dp[2][j-1]+dp[n][j-1];
	    else dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
	}
	printf("%d\n",dp[1][m]);
}
int main()
{
	start();
	solve();
	return 0;
}
