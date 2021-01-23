#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 5000000
using namespace std;
typedef long long ll;
ll n,m,k,start,en,cnt;
ll dis[maxium],head[maxium],vis[maxium];
struct Edge
{
	ll to;
	ll w;
	ll prev;
}edge[maxium];
void add(ll x,ll y,ll w)
{
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
void st()
{
	cin>>n>>m>>start>>en;
	cin>>k;
	start++;en++;
	for(ll i=1;i<=m;i++)
	{
		ll u,v;ll w;
		cin>>u>>v>>w;
		u++;v++;
		add(u,v,w);add(v,u,w);
		for(ll j=1;j<=k;j++)
		{
			add(j*n+u,j*n+v,w);
			add(j*n+v,j*n+u,w);
			add((j-1)*n+u,j*n+v,0);
			add((j-1)*n+v,j*n+u,0);
		}
	}
}
void dijkstra()
{
	priority_queue<pair<ll,ll> >q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[start]=0;
	q.push(make_pair(0,start));
	while(!q.empty())
	{
		ll temp=q.top().second;q.pop();
		if(vis[temp]) continue;
		vis[temp]=1;
		for(ll i=head[temp];i;i=edge[i].prev)
		{
			ll to=edge[i].to;
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
	ll tmp=en,ans=0x3f3f3f3f;
	dijkstra();
	ans=min(ans,dis[tmp]);
	for(ll i=1;i<=k;i++)
	ans=min(ans,dis[i*n+tmp]);
	cout<<ans;
}
int main()
{
	st();
	solve();
	return 0;
}
