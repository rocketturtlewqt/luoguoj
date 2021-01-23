#include<bits/stdc++.h>
#define soo (1e8)
#define ll long long
using namespace std;
int d,cnt,head[25],dis[25],vis[25],cant_vis[25];
ll co[105][105],dp[105];
int n,m,k,ee,cl[25][105];
struct Edge{
    int v,nx,s;
}e[10005];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-ff;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+ch-'0';ch=getchar();}
    return ret*ff;
}
void add(int x,int y,int z){
    e[++cnt].v=y;
    e[cnt].s=z;
    e[cnt].nx=head[x];
    head[x]=cnt;
}
void spfa(){//爱跑什么跑什么
    for(int i=1;i<=m;i++) dis[i]=soo,vis[i]=0;
    queue<int> q;
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=e[i].nx){
            int v=e[i].v;
            if(cant_vis[v]) continue;
            if(dis[v]>dis[x]+e[i].s){
                dis[v]=dis[x]+e[i].s;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
signed main(){
    n=read(),m=read(),k=read(),ee=read();
    for(int i=1;i<=ee;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,z);
    }
    d=read();
    for(int i=1;i<=d;i++){
        int t=read(),x=read(),y=read();
        for(int j=x;j<=y;j++) cl[t][j]=1;
    }
    //cl[i][j]表示第i个码头在第j天不能走
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            memset(cant_vis,0,sizeof(cant_vis));
            for(int r=i;r<=j;r++)
                for(int l=1;l<=m;l++)
                    if(cl[l][r]) cant_vis[l]=1;
            spfa();
            co[i][j]=dis[m];
        }
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i]=(ll)co[1][i]*i;
        printf("%lld ",co[1][i]);
        for(int j=i-1;j>=0;j--)
        dp[i]=min(dp[i],dp[j]+co[j+1][i]*(i-j)+k);
    }
//    for(int i=1;i<=n;i++)
//    printf("%d ",dp[i]);
//    printf("%lld",dp[n]);
    return 0;
}
