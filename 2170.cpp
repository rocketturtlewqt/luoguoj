#include<cstdio>
#include<string.h>
#include<iostream>
#include<iostream>
#include<math.h>
#define maxium 100500
using namespace std;
int n,m,num,cnt;
int par[maxium],sum[maxium],dp[maxium],book[maxium];
int find(int x)
{
	int r=x;
	while(r!=par[r])
	{
		r=par[r];
	}
	return par[r];
}
void init(int x,int y)
{
	int tx=find(x),ty=find(y);
	if(tx!=ty) 
	{
		par[tx]=ty;
		sum[ty]+=sum[tx];
	}
}
void start()
{
	cin>>n>>num>>m;
	for(int i=1;i<=n;i++)
	{
	    par[i]=i;
	    sum[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		init(x,y);
	}
}
void solve()
{
	
	int minabs=0x3f3f3f3f,minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	if(par[i]==i) book[++cnt]=sum[i];
	for(int i=1;i<=cnt;i++)
	for(int j=2*num;j>=book[i];j--)
	dp[j]=max(dp[j],dp[j-book[i]]+book[i]);
	for(int i=1;i<=2*num;i++)
	{
	    if(abs(dp[i]-num)<minabs)
	    {
	    	minabs=abs(dp[i]-num);
	    	minn=dp[i];
		}
	}
	if(minn==0x3f3f3f3f) cout<<0;
	else cout<<minn;
}
int main()
{
	start();
	solve();
	return 0;
}
