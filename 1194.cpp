#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e6;
struct Edge{
	int u,v,w;
}edge[MAXN];
int a,b,u,v,x,cnt,sum,vis[MAXN],par[MAXN];
inline int find(int x){
	while(x!=par[x]){
		x=par[x];
	}
	return par[x];
}
inline void init(int x,int y){
	if(x!=y) par[x]=y;
}
bool compare(struct Edge a,struct Edge b){
	return a.w<b.w;
}
inline void kruscal(){
	sort(edge+1,edge+cnt+1,compare);
	for(int i=1;i<=cnt;i++){
		int x=find(edge[i].u),y=find(edge[i].v);
		if(x==y) continue;
		init(x,y);
		if(edge[i].w<a) sum+=edge[i].w;
		else sum+=a;
	}
}
int main(){
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	for(int j=1;j<=b;j++){
		scanf("%d",&x);
		if(i<=j&&x!=0){
			edge[++cnt].u=i;
			edge[cnt].v=j;
			edge[cnt].w=x;
		}
	}
	for(int i=1;i<=b;i++) par[i]=i;
	kruscal();
	return printf("%d\n",sum+a),0;
}
