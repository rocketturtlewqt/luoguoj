#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}return x*f;
}
struct node{
    int next,to,w,x,ok;
}e[2000005],b[2000005];
int n,m,xx,xxx,yy,yyy,cnt,vis[1510],head[1510],dis[5][1505],headd[1510],cntt,to[1510],dp[1510];
void spfa(int u,int p){
    vis[u]=1;
    queue<int>q;
    q.push(u);
    for(int i=1;i<=n;i++){
        if(i!=u)dis[p][i]=0x7fffffff/3;
    }
    while(!q.empty()){
        int l=q.front();
        q.pop();
        vis[l]=0;
        for(int i=head[l];i;i=e[i].next){
            int to=e[i].to;
            if(dis[p][to]>dis[p][l]+e[i].w){
                dis[p][to]=dis[p][l]+e[i].w;
                if(!vis[to]){
                    vis[to]=1;q.push(to);
                }
            }
        }
    }
}
int main(){
    n=read();m=read();
    xx=read();yy=read();
    xxx=read();yyy=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        cnt++;e[cnt].to=y;e[cnt].next=head[x];head[x]=cnt;e[cnt].w=z;e[cnt].x=x;
        cnt++;e[cnt].to=x;e[cnt].next=head[y];head[y]=cnt;e[cnt].w=z;e[cnt].x=y;
    }
    printf("cnt=%d\n",cnt);
    spfa(xx,1);spfa(yy,2);spfa(xxx,3);spfa(yyy,4);
    printf("dis1:\n");
    for(int i=1;i<=n;i++) printf("%d ",dis[1][i]);
    printf("\ndis2:\n");
    for(int i=1;i<=n;i++) printf("%d ",dis[2][i]);
    printf("\ndis3:\n");
    for(int i=1;i<=n;i++) printf("%d ",dis[3][i]);
    printf("\ndis4:\n");
    for(int i=1;i<=n;i++) printf("%d ",dis[4][i]);
    printf("\n");
    for(int i=1;i<=cnt;i++){
        if(dis[1][e[i].x]+e[i].w+dis[2][e[i].to]==dis[1][yy]){
            cntt++;
            b[cntt].to=e[i].to;
            if(dis[3][e[i].x]+e[i].w+dis[4][e[i].to]==dis[3][yyy]||dis[4][e[i].x]+e[i].w+dis[3][e[i].to]==dis[3][yyy])b[cntt].ok=1;
                b[cntt].x=e[i].x;
                b[cntt].w=e[i].w;
                b[cntt].next=headd[e[i].x];
                headd[e[i].x]=cntt;
                to[e[i].to]++;

        }
    }
    printf("cntt=%d\n",cntt);
    for(int i=1;i<=n;i++) printf("i=%d %d\n",i,to[i]);
    queue<int>q;
    q.push(xx);
    while(!q.empty()){
        int l=q.front();
        q.pop();
        for(int i=headd[l];i;i=b[i].next){
            to[b[i].to]--;
            if(to[b[i].to]==0){
                q.push(b[i].to);
                dp[b[i].to]=max(dp[b[i].to],dp[l]+b[i].w*b[i].ok);
            }
        }
    }
    cout<<dp[yy];
    return 0;
}
