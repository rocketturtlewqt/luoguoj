#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 500050
using namespace std;
int n,m,q,cnt;
int head[100050],par[100050],deep[100050],node[100050][21],w[100050][21];
struct EDGE
{
	int from;
	int to;
	int w;
}edge1[maxium];
struct Edge
{
	int to;
	int w;
	int prev;
}edge2[maxium];
bool compare(struct EDGE a,struct EDGE b)
{
	return a.w>b.w;
}
int find(int x)
{
    int r=x;
    while(r!=par[r])
    {
    	r=par[r];
	}
	return par[r];
}
void add(int from,int to,int w)
{
	edge2[++cnt].to=to;
	edge2[cnt].w=w;
	edge2[cnt].prev=head[from];
	head[from]=cnt;
}
void start()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&edge1[i].from,&edge1[i].to,&edge1[i].w);
	for(int i=1;i<=n;i++)
	par[i]=i;
	sort(edge1+1,edge1+m+1,compare);
}
void kruskal()
{
	int p=0;
	for(int i=1;i<=m;i++)
	{
		int tx=find(edge1[i].from);
		int ty=find(edge1[i].to);
		if(tx!=ty)
		{
			par[tx]=ty;
			add(edge1[i].from,edge1[i].to,edge1[i].w);
			add(edge1[i].to,edge1[i].from,edge1[i].w);
			p++;
		    if(p==n-1) break;
		}
	}
}
void dfs(int temp)
{
	for(int i=head[temp];i;i=edge2[i].prev)
	{
		int to=edge2[i].to;
		if(deep[to]==0)
		{
			deep[to]=deep[temp]+1;
			node[to][0]=temp;
			w[to][0]=edge2[i].w;
			dfs(to);
		}
	}
}
void build()
{
	for(int i=1;i<=n;i++)
	{
		if(deep[i]==0)
		{
			deep[i]=1;
			node[i][0]=0;
			dfs(i);
		}
	}
//	dfs(1);
   	for(int j=1;j<=20;j++)
	for(int i=1;i<=n;i++)
	{
		node[i][j]=node[node[i][j-1]][j-1];
		w[i][j]=min(w[i][j-1],w[node[i][j-1]][j-1]);
	}
}
int lca(int x,int y)
{
	int ans=0x3f3f3f3f;
	if(deep[x]<deep[y])
	{
		int t;
		t=x;x=y;y=t;
	}
    for(int i=20;i>=0;i--)
    {
    	if(deep[node[x][i]]>=deep[y])
     	{
    		ans=min(ans,w[x][i]);
    		x=node[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=20;i>=0;i--)
	{
		if(node[x][i]!=node[y][i])
		{
			ans=min(ans,min(w[x][i],w[y][i]));
			x=node[x][i];
			y=node[y][i];
		}
	}
	ans=min(ans,min(w[x][0],w[y][0]));
	return ans;
}
int main()
{
	start();
	kruskal();
	build();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int start,end;
		scanf("%d%d",&start,&end);
		if(find(start)!=find(end)) printf("-1\n");
		else printf("%d\n",lca(start,end));
	}
	return 0;
}

