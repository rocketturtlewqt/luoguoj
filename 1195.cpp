#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 10001
using namespace std;
int n,m,k;
int par[1001];
struct Edge
{
	int u,v;
	int w;
}edge[maxium];
int find(int x)
{
    while(x!=par[x])
    {
    	x=par[x];
	}
	return par[x];
}
void init(int x,int y)
{
	if(find(x)!=find(y)) par[find(x)]=find(y);
}
bool compare(struct Edge& a,struct Edge& b)
{
	return a.w<b.w;
}
void start()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+m+1,compare);
	for(int i=1;i<=n;i++)
	par[i]=i;
}
void solve()
{
    int num=n,cost=0;
    if(num==k) 
    {
    	cout<<0;
    	return;
	}
    for(int i=1;i<=m;i++)
    {
		if(find(edge[i].u)!=find(edge[i].v))
		{
			init(edge[i].u,edge[i].v);
			cost+=edge[i].w;
			num--;
		}
		if(num==k)
    	{
    		cout<<cost;
    		return;
		}
	}
	cout<<0;
}
int main()
{
	start();
	solve();
	return 0;
}
