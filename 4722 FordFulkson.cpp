#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 1201
#define fp(i,w,n) for(int i=w;i<=n;i++)
using namespace std;
int n,m,s,t;
int map[maxn][maxn],vis[maxn],par[maxn];
inline int read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

inline void out(int a)
{
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
inline void start()
{
	n=read(),m=read(),s=read(),t==read();
	fp(i,1,m) {
		int u,v,w;
		u=read(),v=read(),w=read();
		map[u][v]=w;
	}
}
inline int bfs()
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(par,-1,sizeof(par));
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
		if(temp==t) return 1;
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
inline int max_flow()
{
	int flow=0,minn=0x3f3f3f3f;
	while(bfs())
	{
		int e=t;
		while(par[e]!=-1)
		{
			minn=min(minn,map[par[e]][e]);
			e=par[e];
		}
		flow+=minn;
		e=t;
		while(par[e]!=-1)
		{
			map[par[e]][e]-=minn;
			map[e][par[e]]+=minn;
			e=par[e];
		}
	}
	return flow;
}
inline void solve()
{
    out(max_flow());
}
int main()
{
	start();
	solve();
	return 0;
}
int dfs(int x,int a)
{
	if(x==t||a==0) return a;
	int flow=0,f;
    for(int &i=cur[x];i<G[x].size();i++)
	{
		struct Edge &e=edge[G[x][i]];
		int to=e.to;
		if(deep[to]=deep[x]+1&&(f=dfs(to,min(e.w,a)))>0){
			e.w-=f,edge[G[x][i]^1].w+=f,a-=f,flow+=f;
			if(a==0) break;
		}
	}
	return flow;
}

