#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 100002
using namespace std;
int n,m;
int par[maxium],b[maxium];
struct Edge
{
	int u;
	int v;
	int w;
}edge[maxium];
bool compare(struct Edge& a,struct Edge& b)
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
void init(int x,int y)
{
	if(find(x)!=find(y)) 
	par[find(x)]=find(y);
	return;
}
void start()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+m+1,compare);
	for(int i=1;i<=n;i++)
	par[i]=i;
}
void solve()
{
	for(int i=1;i<=m+1;i++)
	{
        if(find(edge[i].u)==find(edge[i].v)) 
		{
			cout<<edge[i].w;
			break;
		}
        else
        {
        	if(!b[edge[i].u]) b[edge[i].u]=edge[i].v;
        	else init(b[edge[i].u],edge[i].v);
        	if(!b[edge[i].v]) b[edge[i].v]=edge[i].u;
        	else init(edge[i].u,b[edge[i].v]);
		}
	}
}
int main ()
{
	start();
	solve();
	return 0;
}
