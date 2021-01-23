#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxn 5001
using namespace std;
int N;
int money[maxn],dp[maxn],book[maxn];
void start()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	cin>>money[i];
}
void solve()
{
	int res=0,cnt=0;
	for(int i=1;i<=N;i++)
	{
		dp[i]=1;book[i]=1;
	    for(int j=1;j<i;j++)
		if(money[j]>money[i]) dp[i]=max(dp[i],dp[j]+1);
//		if(dp[i]==0) dp[i]++;
		res=max(res,dp[i]);
		for(int j=1;j<i;j++)
		{
		   	if(money[j]==money[i]&&dp[j]==dp[i]) book[j]=0;
		   	else if(money[j]>money[i]&&dp[j]+1==dp[i]) book[i]+=book[j];
		}
//		if(!book[i]) book[i]=1;
	}
	for(int i=1;i<=N;i++)
	if(dp[i]==res)
	cnt+=book[i];
	printf("%d %d\n",res,cnt);
} 
int main ()
{
	start();
	solve();
	return 0;
}
