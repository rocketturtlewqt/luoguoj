#include<stdio.h>
#include<string.h>
#include<queue>
#define maxium 400010
using namespace std;
int N,M,cnt;
int head[maxium],dis[maxium],vis[maxium],ans[maxium];
struct Edge
{
	int next,to;
}edge[maxium];
void add_edge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void spfa(int s)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head[temp];i;i=edge[i].next)
		{
			if(dis[edge[i].to]>dis[temp]+1)
			{
				dis[edge[i].to]=dis[temp]+1;
				ans[edge[i].to]=ans[temp];
				if(!vis[edge[i].to])
			    {
				    q.push(edge[i].to);
				    vis[edge[i].to]=1;
			    }
			}
			else if(dis[edge[i].to]==dis[temp]+1) ans[edge[i].to]=(ans[edge[i].to]+ans[temp])%100003;
		}
	}
}
int main ()
{
	int u,v;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
	    scanf("%d%d",&u,&v);
	    add_edge(u,v);
	    add_edge(v,u);
	}
	ans[1]=1;
	spfa(1);
	for(int i=1;i<=N;i++)
	printf("%d\n",ans[i]);
}
