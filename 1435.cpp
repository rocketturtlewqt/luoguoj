#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 3000
using namespace std;
int n;
char s1[maxium],s2[maxium];
int dp[maxium][maxium];
void start()
{
	gets(s1);
	n=strlen(s1);
	for(int i=0;i<=n-1;i++)
	s2[i]=s1[n-i-1];
}
void solve()
{
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	{
		if(s1[i]==s2[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
		else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
	}
	cout<<n-dp[n][n];
}
int main()
{
	start();
	solve();
	return 0;
}
