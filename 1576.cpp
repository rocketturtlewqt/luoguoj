#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#define maxium 2050
using namespace std;
int n,m,startp,endp;
int used[maxium];
double cost[maxium][maxium],dis[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j) cost[i][j]=0;
		else cost[i][j]=100000000.0;
	}
	for(int i=1;i<=m;i++)
	{
		int p1,p2;
		double w;
		cin>>p1>>p2>>w;
	    cost[p1][p2]=cost[p2][p1]=w/100.0;
	}
	cin>>startp>>endp;
}
void dijkstra(int end)
{
    for(int i=1;i<=n;i++)
    dis[i]=100000000.0;
	dis[end]=100.0;
	while(1)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		if(!used[u]&&(v==-1||dis[u]<dis[v])) v=u;
		if(v==-1) break;
		used[v]=1;
		for(int u=1;u<=n;u++)
		if(cost[v][u]!=100000000.0)
		dis[u]=min(dis[u],dis[v]/fabs(1.0-cost[v][u]));
	}
	printf("%.8lf\n",dis[startp]);
}
int main()
{
	start();
	dijkstra(endp);
	return 0;
}
