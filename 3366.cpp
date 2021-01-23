#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 500001
using namespace std;
int n,m,cnt;
long res;
int par[50001];
struct Edge
{
	int u;
	int v;
	long w;
}edge[maxium];
bool compare(struct Edge a,struct Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
    if(x==par[x]) return x;
    else return find(par[x]);
}
void init(int x,int y)
{
	int tx=find(x),ty=find(y);
	if(tx!=ty) par[tx]=ty;
}
void start()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    par[i]=i;
	for(int i=1;i<=m;i++)
    scanf("%d%d%ld",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge+1,edge+m+1,compare);
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int u=edge[i].u,v=edge[i].v;
		if(find(u)!=find(v)) 
		{
			init(u,v);
			cnt++;
			res+=edge[i].w;
		}
		if(cnt==n-1) break;
	}
    if(cnt<n-1) cout<<"orz";
    else cout<<res;
}
int main()
{
	start();
	solve();
	return 0;
}

