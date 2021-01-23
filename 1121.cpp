#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxium 200001
using namespace std;
int dp[maxium][4][2],a[maxium];
int n;
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
}
void solve()
{
	int max1,max2,maxx;
	memset(dp,128,sizeof(dp));
	dp[1][1][1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]);
		dp[i][1][1]=max(dp[i-1][1][1]+a[i],a[i]);
		dp[i][2][0]=max(dp[i-1][2][0],dp[i-1][2][1]);
		dp[i][2][1]=max(dp[i-1][1][0],max(dp[i-1][1][1],dp[i-1][2][1]))+a[i];
//		dp[i][2][1]=max(dp[i-1][1][0]+a[i],dp[i-1][2][1]+a[i]);
	}
	max1=max(dp[n][2][0],dp[n][2][1]);
	memset(dp,128,sizeof(dp));
	dp[1][1][1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]);
		dp[i][1][1]=dp[i-1][1][1]+a[i];
		dp[i][2][0]=max(dp[i-1][2][0],dp[i-1][2][1]);
		dp[i][2][1]=max(dp[i-1][1][0],max(dp[i-1][1][1],dp[i-1][2][1]))+a[i];
//		dp[i][2][1]=max(dp[i-1][1][0]+a[i],dp[i-1][2][1]+a[i]);
		dp[i][3][0]=max(dp[i-1][3][0],dp[i-1][3][1]);
		dp[i][3][1]=max(dp[i-1][2][0],max(dp[i-1][2][1],dp[i-1][3][1]))+a[i];
//		dp[i][3][1]=max(dp[i-1][2][0]+a[i],dp[i-1][3][1]+a[i]);
	}
	max2=dp[n][3][1];
	maxx=max(max1,max2);
	cout<<maxx;
}
int main ()
{
	start();
	solve();
	return 0;
}
