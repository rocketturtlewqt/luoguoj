#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 5000000
using namespace std;
int n,m,s,cnt,ans,maxx;
int vis[maxium],head1[maxium],head2[maxium],dis1[maxium],dis2[maxium];
struct Edge
{
	int to;
	int prev;
	int w;
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
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
}
void spfa1()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis2,0x3f3f3f3f,sizeof(dis2));
	dis2[s]=0;
	q.push(s);vis[s]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head1[temp];i;i=edge1[i].prev)
		{
			int to=edge1[i].to;
			if(dis2[to]>dis2[temp]+edge1[i].w)
			{
				dis2[to]=dis2[temp]+edge1[i].w;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
void spfa2()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis1,0x3f3f3f3f,sizeof(dis1));
	dis1[s]=0;
	q.push(s);vis[s]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head2[temp];i;i=edge2[i].prev)
		{
			int to=edge2[i].to;
			if(dis1[to]>dis1[temp]+edge2[i].w)
			{
				dis1[to]=dis1[temp]+edge2[i].w;
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
	spfa1();
	spfa2();
	for(int i=1;i<=n;i++)
	maxx=max(maxx,dis1[i]+dis2[i]);
	cout<<maxx;
}
int main()
{
	start();
	solve();
	return 0;
}
