#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 40001
using namespace std;
int n,m,s,t,cnt;
int head[20001],vis[20001],dis[20001];
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
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
}
void spfa()
{
	queue<int> q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	q.push(s);vis[s]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head[temp];i;i=edge[i].prev)
		{
			int to=edge[i].to;
			if(max(dis[temp],edge[i].w)<dis[to]) 
			{
				dis[to]=max(dis[temp],edge[i].w);
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
int main()
{
	start();
	spfa();
	cout<<dis[t];
	return 0;
}
