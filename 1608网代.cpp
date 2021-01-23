#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 2100
#define maxn 9999999
using namespace std;
bool vis[N];
int n,m,x,y,z,tot;
int dis[N],sum[N],head[N],f[N][N];
queue<int>q;
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int spfa(int s)
{
    for(int i=1;i<=n;i++) 
	{
		dis[i]=maxn;vis[i]=false;sum[i]=1;
	}
    dis[s]=0,vis[s]=true; q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        	        if(x==n) continue;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]>dis[x]+f[x][i])
            {
                dis[i]=dis[x]+f[x][i];
                sum[i]=sum[x];
                if(sum[i]&&!vis[i])
                vis[i]=true,q.push(i);
            }
            else if(dis[i]==dis[x]+f[x][i])
                   sum[i]+=sum[x];
        }
        vis[x]=false;
        sum[x]=0;
    }
}
int main()
{
    memset(f,maxn,sizeof(f));
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        x=read(),y=read(),z=read();
         f[x][y]=min(f[x][y],z);
    } 
    spfa(1);
    if(dis[n]==maxn) printf("No answer");
    else printf("%d %d",dis[n],sum[n]);
}
