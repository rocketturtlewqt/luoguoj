#include<stdio.h>
#include<string.h>
#include<queue>
#define maxn 101
using namespace std;
int mixx=0x3f3f3f3f,n,cnt;
int dis[maxn],person[maxn],head[maxn],vis[maxn];
queue<int> q;
struct Edge
{
	int to,prev;
}edge[maxn];
void add_edge(int a,int b)
{
	edge[++cnt].to=b;
	edge[cnt].prev=head[a];
	head[a]=cnt;
}
void start()
{
	int left,right;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&person[i],&left,&right);
        if(left!=0)
        {
        	add_edge(i,left);
        	add_edge(left,i);
		}
		if(right!=0)
		{
			add_edge(i,right);
			add_edge(right,i);
		}
	}
}
void spfa(int x)
{
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push(x);vis[x]=1;dis[x]=0;
    while(!q.empty())
    {
    	int temp=q.front();q.pop();vis[temp]=0;
    	for(int i=head[temp];i;i=edge[i].prev)
    	{
    		int to=edge[i].to;
    		if(dis[to]>dis[temp]+1)
    		{
    			dis[to]=dis[temp]+1;
    			if(!vis[to])
    			{
    				q.push(to);
    				vis[to]=1;
				}
			}
		}
	}
}
int main ()
{
	int sum;
	start();
    for(int i=1;i<=n;i++)
    {
    	sum=0;
    	spfa(i);
    	for(int j=1;j<=n;j++)
    	{
    	    sum+=dis[j]*person[j];
    	}
    	mixx=min(sum,mixx);
	}
	printf("%d\n",mixx);
	return 0;
}
