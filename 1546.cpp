#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 120
using namespace std;
int n,m;
int map[maxium][maxium],used[maxium],dis[maxium];
void start()
{	
    cin>>n;
	memset(map,0x3f3f3f3f,sizeof(map));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		int w;
		cin>>w;
		if(w) map[i][j]=w;
	}
}
void prim()
{
	int res=0;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
	while(1)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		if(!used[u]&&(v==-1||dis[u]<dis[v])) v=u;
		if(v==-1) break;
		used[v]=1;
		res+=dis[v];
		for(int u=1;u<=n;u++)
		dis[u]=min(dis[u],map[v][u]);
	}
	cout<<res;
}
int main()
{
	start();
	prim();
	return 0;
}

