#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 500050
using namespace std;
int n,m,b,cnt;
int dis[maxium],vis[maxium],head[maxium];
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
	cin>>n>>m>>b;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
}
void spfa(int start)
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f3f,sizeof(dis));
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
	int sum;
	spfa(1);
	while(b--)
	{
		int start,end;
		sum=0;
		cin>>start>>end;
		sum+=dis[start]+dis[end];
		cout<<sum<<endl;
	}
}
int main()
{
	start();
	solve();
	return 0;
}
