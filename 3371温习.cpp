#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=4e6+5;
struct Edge{
    int to,w,prev;
}edge[MAXN];
int n,m,s,cnt,dis[MAXN],head[MAXN],vis[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;edge[cnt].w=w;
	edge[cnt].prev=head[x];head[x]=cnt;
}
inline void dijkstra(){
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push({0,s});dis[s]=0;
	while(q.size()){
		int tmp=q.top().second;q.pop();
		if(vis[tmp]) continue;
		vis[tmp]=1;
		for(int i=head[tmp];i;i=edge[i].prev){
			int to=edge[i].to;
			if(dis[to]>dis[tmp]+edge[i].w){
				dis[to]=dis[tmp]+edge[i].w;
				if(!vis[to]) q.push({-dis[to],to});
			}
		}
	}
	fp(i,1,n){
		if(dis[i]==0x3f3f3f3f) printf("%d ",2147483647);
		else printf("%d ",dis[i]);
	}
}
int main(){
	scff(n,m,s);
	fp(i,1,m){
		int u,v,w;scff(u,v,w);
		add(u,v,w);
	}
	dijkstra();
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=4e6+5;
struct Edge{
	int to,w,prev;
}edge[MAXN];
int n,m,s,cnt,head[MAXN],vis[MAXN],dis[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void dijkstra(int st){
	priority_queue<pair<int,int> > q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push({0,st});dis[st]=0;
	while(!q.empty()){
		int tmp=q.top().second;q.pop();
		if(vis[tmp]) continue;
		vis[tmp]=1;
		for(int i=head[tmp];i;i=edge[i].prev){
			int to=edge[i].to;
			if(dis[to]>dis[tmp]+edge[i].w){
				dis[to]=dis[tmp]+edge[i].w;
				q.push({-dis[to],to});
			}
		}
	}
	fp(i,1,n){
		if(dis[i]==0x3f3f3f3f) printf("%d ",2147483647);
		else printf("%d ",dis[i]);
	}
}
int main(){
	scff(n,m,s);
	fp(i,1,m){
		int u,v,w;
		scff(u,v,w);
		add(u,v,w);
	}
	dijkstra(s);
	return 0;
}
*/
