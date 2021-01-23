#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 1000020
using namespace std;
int n,m,cnt,ans;
long long cost;
int vis[maxium],head1[maxium],head2[maxium];
int dis[maxium];
struct Edge
{
	int to;
	int w;
	int prev;
}edge1[maxium],edge2[maxium];
void add(int x,int y,int w)
{
	edge1[++cnt].to=y;
	edge1[cnt].w=w;
	edge1[cnt].prev=head1[x];
	head1[x]=cnt;
	edge2[++ans].to=x;
	edge2[ans].w=w;
	edge2[ans].prev=head2[y];
	head2[y]=ans;
}
void start()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
}
void spfa1()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head1[temp];i;i=edge1[i].prev)
		{
			int to=edge1[i].to;
			if(dis[to]>dis[temp]+edge1[i].w)
			{
				dis[to]=dis[temp]+edge1[i].w;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	cost+=dis[i];
}
void spfa2()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head2[temp];i;i=edge2[i].prev)
		{
			int to=edge2[i].to;
			if(dis[to]>dis[temp]+edge2[i].w)
			{
				dis[to]=dis[temp]+edge2[i].w;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	cost+=dis[i];
}
void solve()
{
	spfa1();
	spfa2();
	printf("%lld\n",cost);
}
int main()
{
	start();
	solve();
	return 0;
}
