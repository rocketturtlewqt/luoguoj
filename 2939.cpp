#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 7000000
using namespace std;
typedef long long ll;
int n,m,k,cnt;
int head[maxium],vis[maxium];
int dis[maxium];
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
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
		for(int j=1;j<=k;j++)
		{
			add(j*n+u,j*n+v,w);add(j*n+v,j*n+u,w);
			add((j-1)*n+u,j*n+v,0);add((j-1)*n+v,j*n+u,0);
		}
	}
}
void dijkstra()
{
	priority_queue<pair<int,int> > q;
//    queue<int> q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push(make_pair(0,1));
//    q.push(1);
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
//                q.push(to);
			}
		}
	}
}
void solve()
{
	int ans=0x3f3f3f3f;
	int tmp=n;
	dijkstra();
//	for(int i=1;i<=n;i++)
//	printf("%d ",dis[i]);
	ans=min(ans,dis[tmp]);
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
