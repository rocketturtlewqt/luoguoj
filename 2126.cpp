#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6;
struct Edge{
	int x,y,w;
}edge[MAXN];
int n,m,sum,cnt,u,v,t,par[MAXN];
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
bool comapre(struct Edge a,struct Edge b){
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
	n=read();m=read();
	for(int i=1;i<=m;i++){
		u=read();v=read();t=read();
		add(u,v,t);
	}
}
inline void kruscal(){
	int ans=0;
	sort(edge+1,edge+cnt+1,comapre);
	for(int i=1;i<=n;i++) par[i]=i;
	for(int i=1;i<=cnt;i++){
	    int x=edge[i].x,y=edge[i].y;
		int tx=find(x),ty=find(y);
		if(tx==ty) continue;
		par[tx]=ty;
		sum+=edge[i].w;	
		if(ans==n) break;
	}
}
int main(){
	start();
	kruscal();
	out(sum),putchar('\n');
	return 0;
}
