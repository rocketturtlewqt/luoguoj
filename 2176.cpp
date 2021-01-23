#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxium 101
using namespace std;
int n,m,maxx,first;
int d[maxium][maxium],vis[maxium],head[maxium],dis[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j) d[i][i]=0;
		else d[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
	}
}
void dijkstra()
{
	memset(vis,0,sizeof(vis));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(head,0,sizeof(head));
    dis[1]=0;
    while(1)
    {
    	int v=-1;
    	for(int u=1;u<=n;u++)
    	if(!vis[u]&&(v==-1||dis[u]<dis[v])) v=u;
		if(v==-1) break;
		vis[v]=1;
		for(int u=1;u<=n;u++)
		{
			if(dis[u]>dis[v]+d[v][u])
			{
				dis[u]=dis[v]+d[v][u];
				head[u]=v;
			}
		}
	}
}
void dijkstra2()
{
	memset(vis,0,sizeof(vis));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
    while(1)
    {
    	int v=-1;
    	for(int u=1;u<=n;u++)
    	if(!vis[u]&&(v==-1||dis[u]<dis[v])) v=u;
		if(v==-1) break;
		vis[v]=1;
		for(int u=1;u<=n;u++)
		{
			if(dis[u]>dis[v]+d[v][u]) dis[u]=dis[v]+d[v][u];
		}
	}
}
int main()
{
	int h=0;
	start();
	dijkstra();
	first=dis[n];
//	printf("%d\n",dis[n]);
    for(int i=n;head[i]!=0;i=head[i])
//    maxx=max(maxx,d[head[i]][i]);
//    for(int i=n;head[i]!=0;i=head[i])
//    if(d[head[i]][i]==maxx)
	{
	    d[head[i]][i]*=2;d[i][head[i]]*=2;
	    dijkstra2();
	    d[head[i]][i]/=2;d[i][head[i]]/=2;
//	    printf("%d\n",dis[n]);
        h=max(h,dis[n]);
    }
    cout<<h-first; 
	return 0;
}
