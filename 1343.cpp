#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<queue>
#define maxium 300
using namespace std;
int n,m,x;
int map[maxium][maxium],flag[maxium],par[maxium];
void start()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		map[u][v]+=w;
	}
}
int bfs()
{
	queue<int> q;
	memset(flag,0,sizeof(flag));
	memset(par,-1,sizeof(par));
	while(!q.empty()) q.pop();
	q.push(1);flag[1]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
		if(temp==n) return 1;
		for(int i=1;i<=n;i++)
		{
			if(i!=temp&&map[temp][i]&&!flag[i])
			{
				par[i]=temp;
				q.push(i);
				flag[i]=1;
			}
		}
	}
	return 0;
}
int max_flow()
{
	int flow=0;
	while(bfs())
	{
		int end=n,minn=0x3f3f3f3f;
		while(par[end]!=-1)
		{
			minn=min(minn,map[par[end]][end]);
			end=par[end];
		}
		end=n;
		flow+=minn;
		while(par[end]!=-1)
		{
			map[par[end]][end]-=minn;
			map[end][par[end]]+=minn;
			end=par[end];
		}
	}
	return flow;
}
void solve()
{
	int maxx=max_flow();
	if(maxx) 
	{
		if(x%maxx!=0) printf("%d %d\n",maxx,x/(maxx)+1);
		else printf("%d %d\n",maxx,x/maxx);
	}
	else printf("Orz Ni Jinan Saint Cow!\n");
}
int main()
{
	start();
	solve();
	return 0;
}

