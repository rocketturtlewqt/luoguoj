#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxium 1200000
using namespace std;
int n,m,root,cnt;
int node[500050][21],deep[500050],lg[500050],head[500050];
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
void dfs(int f,int fath) //f表示当前节点，fath表示它的父亲节点
{
    deep[f]=deep[fath]+1;
    node[f][0]=fath;
    for(int i=1;(1<<i)<=deep[f];i++)
    node[f][i]=node[node[f][i-1]][i-1]; //这个转移可以说是算法的核心之一
    //意思是f的2^i祖先等于f的2^(i-1)祖先的2^(i-1)祖先
    //2^i=2^(i-1)+2^(i-1)
    for(int i=head[f];i;i=edge[i].prev)
    if(edge[i].to!=fath)
    dfs(edge[i].to,f);
}
int lca(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);
    while(deep[x]>deep[y])
    x=node[x][lg[deep[x]-deep[y]]-1];
    if(x==y) return x;
    for(int k=lg[deep[x]]-1;k>=0;k--)
    if(node[x][k]!=node[y][k])
    {
        x=node[x][k];
		y=node[y][k];
	}
    return node[x][0];
}

void solve()
{
	scanf("%d%d%d",&n,&m,&root);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(root,0);
	for(int i=1;i<=n;i++)
    lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	    printf("%d\n",lca(u,v));
	}
}
int main()
{
	solve();
	return 0;
}

