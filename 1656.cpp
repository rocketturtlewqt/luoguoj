#include<stdio.h>
#include<string.h>
#include<algorithm>
#define mxn 151
#define mam 50001
using namespace std;
int head[mxn],dfn[mxn],low[mxn],n,m,mct,dtime,cnt;
struct Edge
{
	int v,prev;
}e[mam];
struct Node
{
	int a,b;
}ans[mxn];
bool operator<(struct Node a,struct Node b)
{
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}
int min (int i,int j)
{
	return i>j?j:i;
}
void add_edge(int u,int v)
{
	e[++mct].v=v;
	e[mct].prev=head[u];
	head[u]=mct;
}
void dfs(int u,int fa)
{
	dfn[u]=low[u]=++dtime;
	for(int i=head[u];i;i=e[i].prev)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[v],low[u]);
			if(low[v]>dfn[u])
			{
				ans[++cnt].a=u;
				ans[cnt].b=v;
			    if(ans[cnt].a>ans[cnt].b) swap(ans[cnt].a,ans[cnt].b);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	return;
}
int main () 
{
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++)
	if(!dfn[i]) dfs(i,0);
	sort(ans+1,ans+cnt+1);
	for(int i=1;i<=cnt;i++)
	printf("%d %d\n",ans[i].a,ans[i].b);
	return 0;
}
