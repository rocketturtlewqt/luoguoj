#include<bits/stdc++.h>
    #define il inline
    using namespace std;
    const int N=100005,inf=23333333;
    int n,m,s,t=520,h[N],cnt=1,dis[N],ans;
    struct edge{
    int to,net,v;
    }e[N*4];
    il void add(int u,int v,int w)
    {
        e[++cnt].to=v,e[cnt].net=h[u],e[cnt].v=w,h[u]=cnt;
        e[++cnt].to=u,e[cnt].net=h[v],e[cnt].v=0,h[v]=cnt;
    }
    queue<int>q;
    il bool bfs()
    {
        memset(dis,-1,sizeof(dis));
        q.push(s),dis[s]=0;
        while(!q.empty())
        {
        	printf("2 ");
            int u=q.front();q.pop();
            for(int i=h[u];i;i=e[i].net)
            if(dis[e[i].to]==-1&&e[i].v>0)dis[e[i].to]=dis[u]+1,q.push(e[i].to);
        }
        return dis[t]!=-1;
    }
    il int dfs(int u,int op)
    {
        if(u==t)return op;
        int flow=0,used=0;
        for(int i=h[u];i;i=e[i].net)
        {
            int v=e[i].to;
            if(dis[v]==dis[u]+1&&e[i].v>0)
            {
                used=dfs(v,min(op,e[i].v));
                if(!used)continue;
                flow+=used,op-=used;
                e[i].v-=used,e[i^1].v+=used;
                if(!op)break;
            }
        }
        if(!op)dis[u]=-1;
        return flow;
    }
    int main()
    {
        scanf("%d%d",&n,&m);
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x==1)add(s,i,1);
            else add(i,t,1);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            add(x,y,1),add(y,x,1);
        }
        while(bfs())ans+=dfs(s,inf);
        cout<<ans;
        return 0;
}
