#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,money,cnt;
int cost[10001],value[10001],book[10001],c[10001],v[10001],par[10001],dp[10001];
int find(int x)
{
	int r=x;
	while(r!=par[r])
	{
		r=par[r];
	}
	return par[r];
}
int query(int x)
{
	int r=x,pa=find(r);
	while(r!=par[r])
	{
		if(!book[r]) 
		{
			book[r]=r;
			c[pa]+=cost[r];
			v[pa]+=value[r];
		}
		r=par[r];
	}
	if(!book[par[r]])
	{
		book[par[r]]=1;
		c[pa]+=cost[par[r]];
		v[pa]+=value[par[r]];
	}
	return par[r];
}
void init(int x,int y)
{
	int tx=find(x),ty=find(y);
	if(tx!=ty) par[tx]=ty;
}
void start()
{
	cin>>n>>m>>money;
	for(int i=1;i<=n;i++)
	{
	    cin>>cost[i]>>value[i];
	    par[i]=i;
	}
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		init(u,v);
	}
	for(int i=1;i<=n;i++)
	query(i);
//	printf("\n");
	for(int i=1;i<=10000;i++)
	if(c[i]!=0) 
	{
		c[++cnt]=c[i];
		v[cnt]=v[i];
	}
    for(int i=1;i<=cnt;i++)
    for(int j=money;j>=c[i];j--)
    dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
    cout<<dp[money];
}
int main()
{
    start();
    solve();
	return 0;
}
