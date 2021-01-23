#include<string.h>
#include<algorithm>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define maxium 400050
using namespace std;
int m,n,st,end1,end2,cnt;
int head[maxium],dis[maxium],vis[maxium];
struct Edge
{
	int to;
	int w;
	int prev;
}edge[maxium];
void add(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
void start()
{
	scanf("%d%d%d%d%d",&m,&n,&st,&end1,&end2);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
}
void dijkstra(int s)
{
	priority_queue<pair<int,int> > q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int temp=q.top().second;q.pop();
		if(vis[temp]) continue;
		vis[temp]=1;
		for(int i=head[temp];i;i=edge[i].prev)
		{
			int to=edge[i].to;
			if(dis[to]>dis[temp]+edge[i].w)
			{
				dis[to]=dis[temp]+edge[i].w;
				q.push(make_pair(-dis[to],to));
			}
		}
	}
}
void solve()
{
	dijkstra(st);
	int p1=dis[end1],p2=dis[end2];
	dijkstra(end1);
	int a=dis[end2];
	printf("%d\n",min(p1,p2)+a);
}
int main()
{
	start();
	solve();
	return 0;
}
