#include<cstdio>
#include<string.h>
#include<iostream>
#include<iostream>
#define maxium 100000
using namespace std;
int n,m;
int a[maxium],dp[maxium][600];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    cin>>a[i];
    dp[1][1]=a[1];
}
void solve()
{   
    for(int i=1;i<=n;i++)
    for(int j=0;j<=m;j++)
    if(j<=i)
    {
		if(j==0) dp[i][0]=max(dp[i][0],dp[i-1][0]);
		else dp[i+j][0]=max(dp[i+j][0],dp[i][j]);
		dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+a[i+1]);
	}
	cout<<dp[n][0];
}
int main()
{
	start();
	solve();
	return 0;
}


