#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<queue>
#define maxium 1500
using namespace std;
int n,m,s,t;
int map[maxium][maxium],vis[maxium],par[maxium];
void start()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v]=w;
	}
}
int bfs(int start,int end)
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(par,-1,sizeof(par));
	q.push(start);
	vis[start]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
		if(temp==end) return 1;
		for(int i=1;i<=n;i++)
		{
			if(map[temp][i]&&!vis[i])
			{
				par[i]=temp;
				q.push(i);
				vis[i]=1;
			}
		}
	}
	return 0;
}
int max_flow(int start,int end)
{
	int flow=0,minn=0x3f3f3f3f;
	while(bfs(start,end))
	{
		int e=end;
		while(par[e]!=-1)
		{
			minn=min(minn,map[par[e]][e]);
			e=par[e];
		}
		flow+=minn;
		e=end;
		while(par[e]!=-1)
		{
			map[par[e]][e]-=minn;
			map[e][par[e]]+=minn;
			e=par[e];
		}
	}
	return flow;
}
void solve()
{
	printf("%d\n",max_flow(s,t));
}
int main()
{
	start();
	solve();
	return 0;
}
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define maxium 1500
using namespace std;
int n,m,s,t;
int deep[maxium],cur[maxium];
struct Edge
{
	int to;
	int w;
};
vector<Edge> edge;
vector<int> G[maxium];
void add(int from,int to,int w)
{
	edge.push_back((Edge){to,w});
	edge.push_back((Edge){from,0});
	int id=edge.size();
	G[from].push_back(id-2);
	G[to].push_back(id-1);
}
void start()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
}
int bfs()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(deep,0,sizeof(deep));
	q.push(s);deep[s]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
		if(temp==t) return 1;
		for(int i=0;i<G[temp].size();i++)
		{
			struct Edge& e=edge[G[temp][i]];
			if(!deep[e.to]&&e.w>0)
			{
				deep[e.to]=deep[temp]+1;
				q.push(e.to);
			}
		}
	}
	return 0;
}
int dfs(int x,int a)
{
	if(x == t || a == 0) return a; 
	int flow = 0, f; 
	for(int& i=cur[x]; i<G[x].size(); i++)    
	{
        Edge& e = edge[G[x][i]];   
		if(deep[x]+1 == deep[e.to] && (f=dfs(e.to, min(a, e.w)))>0)  
		{
			e.w -= f;   
			edge[G[x][i]^1].w+=f;
			flow+=f;
			a-=f;
			if(a==0) break;
		}
	}
	return flow;
}
void solve()
{
	int flow=0,a=0x3f3f3f3f;
	while(bfs())
	{
	    memset(cur,0,sizeof(cur));
	    flow+=dfs(s,a);
	}
	cout<<flow;
}
int main()
{
	start();
	solve();
	return 0;
}
