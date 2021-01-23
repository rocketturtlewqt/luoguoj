#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 200
using namespace std;
typedef long long ll;
int n,m,e,k,d,cnt;
int cant_vis[maxium],vis[maxium],dis[maxium],head[maxium],daynode[maxium][maxium];
ll co[maxium][maxium],dp[maxium];
struct Edge
{
	int to;
	ll w;
	int prev;
}edge[10005];
ll min(ll a,ll b)
{
	if(a<b) return a;
	else return b;
}
void add(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
void start()
{
	cin>>n>>m>>k>>e;
	for(int i=1;i<=e;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	cin>>d;
	for(int i=1;i<=d;i++)
	{
		int node,day1,day2;
		cin>>node>>day1>>day2;
		for(int j=day1;j<=day2;j++)
		daynode[node][j]=1;
	}
}
void spfa()
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
		for(int i=head[temp];i;i=edge[i].prev)
		{
			int to=edge[i].to;
			if(cant_vis[to]) continue;
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
void st()
{
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
		memset(cant_vis,0,sizeof(cant_vis));
		for(int r=i;r<=j;r++)
		for(int k=1;k<=m;k++)
		if(daynode[k][r]) cant_vis[k]=1;
		spfa();
		co[i][j]=dis[m];
	}
}
void solve()
{
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i]=co[1][i]*i;
		for(int j=i-1;j>=0;j--)
        dp[i]=min(dp[i],dp[j]+co[j+1][i]*(i-j)+k);
	}
	cout<<dp[n];
} 
int main()
{
	start();
	spfa();
	st();
	solve();
	return 0;
}


