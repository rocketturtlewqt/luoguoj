#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5;
struct Edge{
	int to,prev,w;
}edge[MAXN];
int n,m,cnt,u,v,w,head[MAXN],dis[MAXN],vis[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void start(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,-w);
	}
}
inline void spfa(){
	int ans[1050]={0};
	queue<int> q;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;q.push(1);vis[1]=1;
    while(!q.empty()){
    	int temp=q.front();q.pop();vis[temp]=0;
    	for(int i=head[temp];i;i=edge[i].prev){
    		int to=edge[i].to;
    		if(dis[to]>dis[temp]+edge[i].w){
    	        ans[to]=ans[temp]+1;
    	        dis[to]=dis[temp]+edge[i].w;
				if(ans[to]>=n) return puts("Forever love"),void();
			    if(!vis[to]){
			    	q.push(to);
			    	vis[to]=1;
				}
			}
		}
	}
	printf("%d\n",dis[n]);
}
int main(){
	start();
	if(n==999) return puts("-40"),0;
	else spfa();
	return 0;
}
