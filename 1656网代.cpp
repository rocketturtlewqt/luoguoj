 #include<iostream>
 #include<algorithm>
 #include<cstring>
 #include<cstdio>
 #include<cmath>
 using namespace std;
 const int mxn=350;
// int read(){
//     int x=0,f=1;char ch=getchar();
//     while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//   while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f;
// }
 struct edge{
     int v,nxt;
 }e[12010];
 int hd[mxn],mct=0;
 void add_edge(int u,int v){
     e[++mct].v=v;e[mct].nxt=hd[u];hd[u]=mct;
     return;
 }
 int n,m;
 int dfn[mxn],low[mxn],dtime=0;
 struct node{
     int a,b;
 }ans[mxn];
 bool operator < (node a,node b){
     if(a.a==b.a)return a.b<b.b;
     return a.a<b.a;
 }
 int cnt=0;
 void DFS(int u,int fa){
     low[u]=dfn[u]=++dtime;
     for(int i=hd[u];i;i=e[i].nxt){
         int v=e[i].v;
         if(v==fa)continue;
         if(!dfn[v]){
             DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                ans[++cnt].a=u;
                ans[cnt].b=v;
                if(ans[cnt].a>ans[cnt].b)swap(ans[cnt].a,ans[cnt].b);
            }
        }else low[u]=min(low[u],dfn[v]);
    }
    return;
}
int main(){
//    n=read();m=read();
scanf("%d%d",&n,&m);
    int i,j,u,v;
    for(i=1;i<=m;i++){
//        u=read();v=read();
scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    for(i=1;i<=n;i++){
        if(!dfn[i])DFS(i,0);
    }
    sort(ans+1,ans+cnt+1);
    for(i=1;i<=cnt;i++){
        printf("%d %d\n",ans[i].a,ans[i].b);
    }
     return 0;
}

