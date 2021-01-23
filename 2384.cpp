#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#define maxium 1005
using namespace std;
int n,m,cnt;
int head[maxium],used[maxium],prev[maxium][2];
double dis[maxium];
struct Edge
{
	int to;
	int w;
	int pre;
}edge[1000008];
void add(int start,int end,int w)
{
	edge[++cnt].to=end;
	edge[cnt].w=w;
	edge[cnt].pre=head[start];
	head[start]=cnt;
}
void start()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
}
void memory_spfa()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	dis[i]=10000000.0;
	dis[1]=0;
	q.push(1);used[1]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();used[temp]=0;
		for(int i=head[temp];i;i=edge[i].pre)
		{
//			printf("%d ",i);
			int to=edge[i].to;
//			printf("%d ",temp);
            if(i==3) 
			{
//				cout<<temp;
//				cout<<"\n";
//				printf("%d %d\n",dis[2],dis[3]);
			}
			if(dis[to]>dis[temp]+log(edge[i].w))
			{
//				printf("%d %d %d %d %d\n",temp,i,edge[i].from,edge[i].to,edge[i].w);;
				dis[to]=dis[temp]+log(edge[i].w);
//				if(dis[3]==2) printf("%d %d\n",temp,i);
				prev[to][0]=edge[i].w;
				prev[to][1]=temp;
				if(!used[to])
				{
					q.push(to);
					used[to]=1;
				}
			}
		}
	}
//	cout<<log(3);
//	cout<<dis[3];
//	cout<<prev[2][1];
//	for(int i=n;i;i=prev[i][1])
//	printf("%d ",prev[i][0]);
}
void solve()
{
	int ans=1;
	for(int i=n;i&&prev[i][0];i=prev[i][1])
	{
		ans*=prev[i][0];
		ans%=9987;
	}
	cout<<ans;
}
int main()
{
	start();
	memory_spfa();
	solve();
	return 0;
}

