#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 100050
using namespace std;
int n;
int dp[maxium][3][2],a[maxium][3];
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i][0]>>a[i][1]>>a[i][2];
}
void solve()
{
	int maxx=0;
	for(int j=0;j<=2;j++)
	{
		memset(dp,0,sizeof(dp));
		dp[1][j][0]=dp[1][j][1]=a[1][j];
		for(int i=2;i<=n;i++)
		{
			dp[i][0][0]=max(dp[i-1][1][1],dp[i-1][2][1])+a[i][0];
			dp[i][1][0]=dp[i-1][2][1]+a[i][1];
			dp[i][1][1]=dp[i-1][0][0]+a[i][1];
			dp[i][2][1]=max(dp[i-1][0][0],dp[i-1][1][0])+a[i][2];
		}
		for(int i=0;i<j;i++)
		maxx=max(maxx,dp[n][i][0]);
		for(int i=2;i>j;i--)
		maxx=max(maxx,dp[n][i][1]);
	}
	cout<<maxx;
}
int main()
{
    start();
    solve();
    return 0;
}
