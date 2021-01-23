#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 400000
using namespace std;
int n,m,k,cnt;
int dis[maxium],head[maxium],vis[maxium];
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
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
		for(int j=1;j<=k;j++)
		{
			add(j*n+u,j*n+v,w);add(j*n+v,j*n+u,w);
			add((j-1)*n+u,j*n+v,w/2);add((j-1)*n+v,j*n+u,w/2);
		}
	}
}
void dijkstra()
{
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	q.push(make_pair(0,1));
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
	int tmp=n,ans=0x3f3f3f3f;
	dijkstra();
	ans=min(ans,dis[n]);
	for(int i=1;i<=k;i++)
	ans=min(ans,dis[i*n+tmp]);
	cout<<ans;
}
int main()
{
	start();
	solve();
	return 0;
}
2
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
5 7
2 7

13
3 2 3 4
0
3 5 6 7
0
0
2 8 9
2 10 11
0
0
2 12 13
0
0 
0
5
