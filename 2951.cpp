#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define maxium 100500
using namespace std;
int n,m,cnt;
int head[maxium],vis[maxium],dis[maxium];
struct Edge
{
	int to;
	int prev;
}edge[maxium];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
void start()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
}
void spfa()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head[temp];i;i=edge[i].prev)
		{
			int to=edge[i].to;
			if(dis[to]>dis[temp]+1)
			{
				dis[to]=dis[temp]+1;
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
	int maxx=-1,pos=0,sum=0;
	spfa();
    for(int i=1;i<=n;i++)
    maxx=max(maxx,dis[i]);
    for(int i=1;i<=n;i++)
    {
    	if(maxx==dis[i])
    	{
    		if(!pos) pos=i;
    		sum++;
		}
	}
	cout<<pos<<" "<<maxx<<" "<<sum;
}
int main()
{
	start();
	solve();
	return 0;
}
