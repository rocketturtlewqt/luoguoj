#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scfff(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
const int MAXN=1e4+5;;
struct Edge{
	int to,w,prev;
}edge[MAXN*20];
int n,m,s,t,cnt,maxflow,head[MAXN],vis[MAXN],incf[MAXN],pre[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;edge[cnt].w=w;edge[cnt].prev=head[x];head[x]=cnt;
	edge[++cnt].to=x;edge[cnt].w=0;edge[cnt].prev=head[y];head[y]=cnt;
}
inline int bfs(){
	queue<int> q;incf[s]=0x3f3f3f3f;q.push(s);
	memset(vis,0,sizeof(vis));
	while(q.size()){;
		int tmp=q.front();q.pop();
		for(int i=head[tmp];i;i=edge[i].prev){
		    if(edge[i].w){
		    	int to=edge[i].to;
		    	if(vis[to]) continue;
		    	vis[to]=1;pre[to]=i;q.push(to);
		    	incf[to]=min(incf[tmp],edge[i].w);
		    	if(to==t) return 1;
			}
		}
	}
	return 0;
}
inline void update(){
	int x=t;
	while(x!=s){
		int i=pre[x];
		edge[i].w-=incf[t];
		edge[i^1].w+=incf[t];
		x=edge[i^1].to;
	}
	maxflow+=incf[t];
}
int main(){
	scfff(n,m,s,t);
	cnt=1;
	fp(i,1,m){
		int u,v,w;
		scff(u,v,w);
		add(u,v,w);
	}
	while(bfs()) update();
	printf("%d\n",maxflow);
	return 0;
} 
