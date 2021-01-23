#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 1001
using namespace std;
int n,m;
int dis[maxium],d[maxium][maxium],used[maxium];
void start()
{
	int u,v,w;
	cin>>n>>m;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j) d[i][j]=0;
		else d[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
	}
}
void solve()
{
	int sum=0;
	while(1)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		if(!used[u]&&(v==-1||dis[u]<dis[v])) v=u;
		if(v==-1) break;
		used[v]=1;
		sum=max(sum,dis[v]);
		for(int u=1;u<=n;u++)
		dis[u]=min(dis[u],d[v][u]);
	}
	if(sum==0||sum==0x3f3f3f3f) cout<<-1;
	else cout<<sum;
}
int main ()
{
    start();
    solve();
    return 0;
}
