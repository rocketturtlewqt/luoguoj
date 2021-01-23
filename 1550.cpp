#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e6;
struct Edge{
	int x,y,w;
}edge[MAXN];
int n,cnt,t,sum,par[MAXN];
bool compare(struct Edge a,struct Edge b){
	return a.w<b.w;
}
inline int find(int x){
	while(x!=par[x]){
		x=par[x];
	}
	return par[x];
}
inline void add(int x,int y,int w){
	edge[++cnt].x=x;
	edge[cnt].y=y;
	edge[cnt].w=w;
}
inline void start(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&t),add(i,n+1,t),add(n+1,i,t);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		scanf("%d",&t);
		if(i!=j){add(i,j,t);add(j,i,t);}
	}
}
inline void kruscal(){
	sort(edge+1,edge+cnt+1,compare);
	for(int i=1;i<=n+1;i++) par[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=edge[i].x,y=edge[i].y;
		int tx=find(x),ty=find(y);
		if(tx==ty) continue;
		sum+=edge[i].w;
		par[tx]=ty;
	}
}
inline void solve(){
	kruscal();
	printf("%d\n",sum);
}
int main(){
	start();
	solve();
	return 0;
}
