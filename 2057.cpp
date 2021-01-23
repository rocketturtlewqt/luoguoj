#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define inf 99999999
#define maxium 200001
#define N 100005
using namespace std;
int n,m,s,t,cnt=1,ans,head[N],dis[N];
queue<int> q;
struct Edge
{
	int to;
	int w;
	int next;
}edge[maxium];
int min (int i,int j)
{
	return i>j?j:i;
}
void add_edge(int u,int v,int w)
{
	edge[++cnt].to=v,edge[cnt].w=w,edge[cnt].next=head[u],head[u]=cnt;
	edge[++cnt].to=u,edge[cnt].w=0,edge[cnt].next=head[v],head[v]=cnt;
}
int bfs()
{
	memset(dis,-1,sizeof(dis));
	q.push(s),dis[s]=0;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
	    for(int i=head[temp];i;i=edge[i].next)
	    {
		    int v=edge[i].to;
		    if(dis[v]==-1&&edge[i].w>0)
		    {
		    	dis[v]=dis[temp]+1;
		    	q.push(v);
			}
	    }
	}
	return dis[t]!=-1;
}
int dfs(int u,int op)
{
	if(u==t) return op;
	int flow=0,used=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(dis[v]==dis[u]+1&&edge[i].w>0)
		{
			used=dfs(v,min(op,edge[i].w));
			if(!used) continue;
			flow+=used;op-=used;
			edge[i].w-=used;edge[i^1].w+=used;
			if(!op) break;
		}
	}
	if(!op) dis[u]=-1;
	return flow;
}
int main ()
{
	int x,u,v;
	cin>>n>>m;
	s=n+1;t=n+2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1) add_edge(s,i,1);
		else add_edge(i,t,1);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	while(bfs()) ans+=dfs(s,inf);
	cout<<ans;
	return 0;
}
