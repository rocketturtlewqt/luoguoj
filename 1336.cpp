#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<math.h>
#define maxium 500
using namespace std;
typedef long long ll;
int n,m;
int a[maxium],b[maxium];
ll dp[maxium][maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>a[i]>>b[i];
}
void solve()
{
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	for(int k=0;k<=j;k++)
	{
		ll now=a[i]*pow(k,b[i]);
		if(dp[i][j]==0||i==1) dp[i][j]=dp[i-1][j-k]+now;
		else dp[i][j]=min(dp[i-1][j-k]+now,dp[i][j]);
	}
	cout<<dp[m][n];
}
int main()
{
	start();
	solve();
	return 0;
}

