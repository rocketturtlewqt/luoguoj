#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 5000
using namespace std;
int n,m;
int par[maxium];
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
	if(tx!=ty) par[tx]=ty;
}
void solve()
{
	while(1)
	{
		cin>>n;
		if(n==0) return;
		cin>>m;
		int sum=-1;
		for(int i=1;i<=n;i++)
		par[i]=i;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			init(u,v);
		}
		for(int i=1;i<=n;i++)
		if(par[i]==i) sum++;
		if(sum==-1) cout<<0<<endl;
		else cout<<sum<<endl;
	}
}
int main()
{
	solve();
	return 0;
}
