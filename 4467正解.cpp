#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define p pair<int,int>
#define maxium 5000
using namespace std;
int n,m,k,s,t,cnt,ans;
int dis[51],head1[51],head2[51],vis[51];
//链式向前星 
//edge1为正向边，edge2为反向边 
struct Edge
{
	int to;
	int w;
	int prev;
}edge1[maxium],edge2[maxium];
void add(int x,int y,int w)
{
	//建正向边 
	edge1[++cnt].to=y;
	edge1[cnt].w=w;
	edge1[cnt].prev=head1[x];
	head1[x]=cnt;
    //建反向边 
	edge2[++ans].to=x;
	edge2[ans].w=w;
	edge2[ans].prev=head2[y];
	head2[y]=ans;
} 
void start()
{
	cin>>n>>m>>k>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
}
//跑dijkstra 
void dijkstra()
{
	priority_queue<p> q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[t]=0;
	q.push(p(0,t));
	while(!q.empty())
	{
		int temp=q.top().second;q.pop();
		if(vis[temp]) continue;
		vis[temp]=1;
		for(int i=head2[temp];i;i=edge2[i].prev)
		{
			int to=edge2[i].to;
			if(dis[to]>dis[temp]+edge2[i].w)
			{
				dis[to]=dis[temp]+edge2[i].w;
				q.push(p(-dis[to],to));
			}
		}
	}
}
void solve()
{
	dijkstra();
}
int main()
{
	start();
	solve();
	return 0;
}
