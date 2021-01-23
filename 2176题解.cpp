#include<iostream>
#include<cstring>
#include<cstdio>
#define M 15000
#include<queue> 
#define N 110
using namespace std;
int n,m;
int po,ans;
int head[N],to[M],next[M],len[M],e=1;
void buid(int u,int v,int l)
{
    next[++e]=head[u],head[u]=e;
    to[e]=v,len[e]=l;
}
int dis[N],init[N];
int pre[N],fr[N],that[M],nu;
queue<int> q;
void spfa(int s)
{
    memset(dis,20,sizeof(dis));
    dis[s]=0;init[s]=1,q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();init[now]=0;
        for(int i=head[now];i;i=next[i])
        {
            int j=to[i];
            if(dis[j]>dis[now]+len[i])
            {
                dis[j]=dis[now]+len[i];
                pre[j]=i;fr[j]=now;
                if(!init[j])
                {
                    init[j]=1;q.push(j);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        buid(u,v,l);
        buid(v,u,l);
    }
    spfa(1);po=dis[n];
    int now=n;
    while(now!=1)
    {
        that[++nu]=pre[now];//记路径
        now=fr[now];
    }
    for(int i=1;i<=nu;++i)//枚举路径
    {
        len[that[i]]*=2;
        len[that[i]^1]*=2;
        spfa(1);//操♂作
        ans=max(ans,dis[n]);
        len[that[i]]/=2;
        len[that[i]^1]/=2;
    }
    cout<<ans-po<<endl;//end
    return 0;
} 

