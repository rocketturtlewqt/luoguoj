#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=4e6+5;
struct Edge{
	int to,w,prev;
}edge[MAXN];
int n,m,q,cnt,u,v,z,head[MAXN],dis[MAXN],vis[MAXN];
inline void add(int x,int y,int w){edge[++cnt].to=y;edge[cnt].w=w;edge[cnt].prev=head[x];head[x]=cnt;}
inline void dfs(int x,int fa){
	vis[x]=1;
    for(int i=head[x];i;i=edge[i].prev){
    	int to=edge[i].to;
    	if(to==fa||dis[to]!=-1||vis[to]) continue;
    	dis[to]=edge[i].w^dis[x];
    	dfs(to,x);
	}
}
int main(){
	memset(dis,-1,sizeof(dis));
	scanf("%d%d%d",&n,&m,&q);
	fp(i,1,m){
		scanf("%d%d%d",&u,&v,&z);
		add(u,v,z);add(v,u,z);
	}
	dis[1]=0;dfs(1,-1);
	fp(i,1,q){
		scanf("%d%d",&u,&v);
		printf("%d\n",dis[u]^dis[v]);
	}
	return 0;
}
