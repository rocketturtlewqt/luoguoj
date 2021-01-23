#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxium 200
using namespace std;
int n,m,D,cnt,first,end;
int dis[maxium],vis[maxium],head[maxium],book[maxium][maxium];
struct Edge
{
	int from;
	int to;
	int w;
	int prev;
}edge[maxium];
void add(int x,int y,int w)
{
	edge[++cnt].from=x;
	edge[cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
void start()
{
	cin>>n;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	cin>>D;
	for(int i=1;i<=D;i++)
	{
		int u,v;
		cin>>u>>v;
		book[u][v]=book[v][u]=1;
	}
	cin>>first>>end;
}
void spfa()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push(first);vis[first]=1;dis[first]=0;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head[temp];i;i=edge[i].prev)
		{
			int to=edge[i].to;
			if(!book[temp][to]||!book[to][temp])
			{
//				printf("%d %d %d ",temp,to,book[temp][to]);
				if(dis[to]>dis[temp])
				{
					dis[to]=dis[temp];
					if(!vis[to])
					{
						q.push(to);
						vis[to]=1;
					}
				}
//				printf("%d\n",dis[to]);
			}
			else
			{
//				printf("%d %d %d ",temp,to,book[temp][to]);
			    if(dis[to]>dis[temp]+edge[i].w) 
			    {
				    dis[to]=dis[temp]+edge[i].w;
//				    book[temp][to]=book[to][temp]=0;
				    if(!vis[to])
				    {
					    q.push(to);
					    vis[to]=1;
				    }
			    }
//    		    printf("%d\n",dis[to]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	printf("%d ",dis[i]);
	cout<<dis[end];
}
void solve()
{
	spfa();
}
int main()
{
	start();
	solve();
	return 0;
}



