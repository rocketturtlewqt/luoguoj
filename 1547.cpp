#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define maxium 400001
using namespace std;
int n,m,cnt;
int head[3000],vis[3000],par[3000];
struct Edge
{
	int start;
	int to;
	int w;
	int prev;
}edge[maxium];
bool compare(struct Edge a,struct Edge b)
{
	return a.w<b.w;
}
void add(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
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
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	par[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	    edge[i].start=u;edge[i].to=v;edge[i].w=w;
	}
}
void kruscal()
{
	int sum=0,maxx=0;
	sort(edge+1,edge+m+1,compare);
	for(int i=1;i<=m;i++)
	{
		int x=edge[i].start;
		int y=edge[i].to;
		if(find(x)!=find(y)) 
		{
			init(x,y);
			maxx=max(maxx,edge[i].w);
			sum++;
		}
		if(sum==n-1) break;
	}
	cout<<maxx;
}
void solve()
{
	kruscal();
}
int main()
{
	start();
	solve();
	return 0;
}
