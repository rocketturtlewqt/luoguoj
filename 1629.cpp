#include<stdio.h>
#include<string.h>
#include<queue>
#define maxx 100000
#define inf 99999999
using namespace std;
int ans,head[maxx],dis[maxx],N,M;
long long SUM;
struct edge
{
	int u,v,cost;
}a[maxx];
struct Edge
{
	int from,to,dis,next;
}b[maxx];
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void add(int x,int y,int z)
{
    ans++;
    b[ans].to=y;
    b[ans].dis=z;
    b[ans].next=head[x];
    head[x]=ans;
}
int spfa(int s)
{
	queue<int>q;
	int vis[maxx];
//	memset(dis,0x3f3f3f3f,sizeof(dis));
    for(int i=1;i<=N;i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
	int sum=0;
	q.push(s);vis[s]=1;dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=b[i].next)
		{
			int t=b[i].to;
			if(dis[t]>dis[x]+b[i].dis)
			{
				dis[t]=dis[x]+b[i].dis;
				if(!vis[t])
				{
					q.push(t);
					vis[t]=1;
				}
			}
		}
		vis[x]=0;
	}
	for(int i=2;i<=N;i++)
	sum+=dis[i];
	return sum;
} 
int main ()
{
	int x,y,z,s;
	N=read(),M=read();
	for(int i=1;i<=M;i++)
	{
		x=read(),y=read(),z=read();
//		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].cost);
		add(x,y,z);
		a[i].u=x;a[i].v=y;a[i].cost=z;
	}
	SUM+=spfa(1);s=ans,ans=0;
	memset(dis,0,sizeof(dis));
    memset(head,0,sizeof(head));
    memset(b,0,sizeof(b));
	for(int i=1;i<=s;i++)
	add(a[i].v,a[i].u,a[i].cost);
	SUM+=spfa(1);
	printf("%lld\n",SUM);
	return 0;
}
