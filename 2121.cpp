#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct Edge{
	int x,y,w;
}edge[MAXN*2];
int n,m,k,cnt,u,v,w,sum,p,par[MAXN];
bool comapre(struct Edge a,struct Edge b){
	return a.w>b.w;
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
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
}
inline void kruscal(){
	sort(edge+1,edge+cnt+1,comapre);
	for(int i=1;i<=n;i++) par[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=edge[i].x,y=edge[i].y;
		int tx=find(x),ty=find(y);
		if(tx==ty) continue;
		par[tx]=ty;
		p++;
		sum+=edge[i].w;
		if(p==k) break;
	}
}
int main(){
	start();
	kruscal();
	printf("%d\n",sum);
	return 0; 
}
