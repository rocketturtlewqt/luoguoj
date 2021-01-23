#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct Edge{
	int to,next,w;
}edge[600000];
int n,m,s,cnt,vis[MAXN],dis[MAXN],head[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;edge[cnt].w=w;
	edge[cnt].next=head[x];head[x]=cnt;
}
inline void spfa(){
	queue<int> q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;vis[s]=1;q.push(s);
	while(!q.empty()){
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head[temp];i;i=edge[i].next){
			int to=edge[i].to;
			if(dis[to]>dis[temp]+edge[i].w){
				dis[to]=dis[temp]+edge[i].w;
				if(!vis[to]) q.push(to),vis[to]=1;
			}
		}
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int start,end,w;cin>>start>>end>>w;
		add(start,end,w);
	}
	spfa();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}
