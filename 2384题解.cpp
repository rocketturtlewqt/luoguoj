#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int st[1100],pre[1100][2],tot;
struct edge
{
    int to,val,last;
}e[1010000];
void add(int a,int b,int c)
{
    e[++tot].to=b;
    e[tot].val=c;
    e[tot].last=st[a];
    st[a]=tot;
}
double dis[1100];
bool judge[1100];
void dij()
{
    for(int i=1;i<=n;i++)
        dis[i]=2147483647;
    dis[1]=0;
    int u=1;
    while(!judge[u])
    {
        judge[u]=true;
        for(int i=st[u];i!=0;i=e[i].last)
        {
            int v=e[i].to;
            if(dis[v]>dis[u]+log(e[i].val))
            {
                dis[v]=dis[u]+log(e[i].val);
                pre[v][0]=e[i].val;
                pre[v][1]=u;
            }
        }
        double minn=2147483647;
        for(int i=1;i<=n;i++)
            if(!judge[i]&&dis[i]<minn)
            {
                minn=dis[i];
                u=i;
            }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
    }
    dij();
    int ans=1,u=n;
    while(pre[u][1]!=0)
    {
        ans*=pre[u][0];
        ans%=9987;
        u=pre[u][1];
    }
    for(int i=n;i;i=pre[i][1])
    printf("%d ",i);
//    printf("%d",ans);
    return 0;
}
