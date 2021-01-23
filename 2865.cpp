#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 300000
using namespace std;
int n,m,cnt,ans=0x3f3f3f3f;
int dis[maxium],disstart[maxium],vis[maxium],head[maxium];
struct Edge
{
	int to;
	int w;
	int prev;
}edge[maxium];
struct Edgestart
{
	int start;
	int to;
	int w;
}edgestart[maxium];
void add(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
void start()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>edgestart[i].start>>edgestart[i].to>>edgestart[i].w;
		add(edgestart[i].start,edgestart[i].to,edgestart[i].w);
		add(edgestart[i].to,edgestart[i].start,edgestart[i].w);
	}
}
void spfa(int start)
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[start]=0;
	q.push(start);vis[start]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head[temp];i;i=edge[i].prev)
		{
			int to=edge[i].to;
			if(dis[to]>dis[temp]+edge[i].w)
			{
				dis[to]=dis[temp]+edge[i].w;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
void solve()
{
	spfa(1);
	for(int i=1;i<=n;i++)
	disstart[i]=dis[i];
	spfa(n);
	for(int i=1;i<=m;i++)
	{
		int u=edgestart[i].start;
		int v=edgestart[i].to;
		int sum1=disstart[u]+dis[v]+edgestart[i].w;
		if(sum1>disstart[n]) ans=min(ans,sum1);
		int sum2=disstart[v]+dis[u]+edgestart[i].w;
		if(sum2>disstart[n]) ans=min(ans,sum2);
	}
	cout<<ans;
}
int main()
{
	start();
	solve();
	return 0;
}
