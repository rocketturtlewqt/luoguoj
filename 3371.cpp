#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=4e6+5;
struct Edge{
	int to,prev,w;
}edge[MAXN];
int n,m,s,u,v,w,cnt,dis[MAXN],vis[MAXN],head[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void dijkstra(int st){
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[st]=0;q.push({0,st});
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
	puts("");
}
int main(){
	scff(n,m,s);
	fp(i,1,m){
		scff(u,v,w);
		add(u,v,w);
	}
	dijkstra(s);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const ll MAXN=4e6+5;
struct Edge{
	int to,prev,w;
}edge[MAXN];
int n,m,s,cnt,u,v,w,dis[MAXN],vis[MAXN],head[MAXN];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void spfa(int st){
    queue<int> q;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    q.push(st);vis[st]=1;dis[st]=0;
    while(!q.empty()){
    	int tmp=q.front();q.pop();vis[tmp]=0;
    	for(int i=head[tmp];i;i=edge[i].prev){
    		int to=edge[i].to;
    		if(dis[to]>dis[tmp]+edge[i].w){
    			dis[to]=dis[tmp]+edge[i].w;
    			if(!vis[to]){
    				q.push(to);
    				vis[to]=1;
				}
			}
		}
	}
	fp(i,1,n){
		if(dis[i]==0x3f3f3f3f) printf("%d ",2147483647);
		else printf("%d ",dis[i]);
	}
	puts("");
}
int main(){
	scff(n,m,s);
	fp(i,1,m){
		scff(u,v,w);
		add(u,v,w);
	}
	spfa(s);
	return 0;
}
/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/
