#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a){
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
int n,m,x1,y11,x2,y22;
struct Edge{
	int from,to,prev,flag,w;
}edge[1000000],e[1000000];
int cnt,head[2000];
inline void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].from=x;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
int he[2000],ans,h;
inline void adds(int x,int y,int w){
	e[++h].to=y;
	e[h].from=x;
	e[h].w=w;
	e[h].prev=he[x];
	he[x]=h;
}
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline void start(){
	n=read(),m=read();
	x1=read(),y11=read(),x2=read(),y22=read();
	fp(i,1,m){
		int x,y,w;x=read(),y=read(),w=read();
		add(x,y,w);add(y,x,w);
	}
}
int vis[2000],dis[2000][5];
inline void dijkstra(int start){
	++ans;
	priority_queue<pair<int,int> >q;
	memset(vis,0,sizeof(vis));
	fp(i,1,n) dis[i][ans]=0x3f3f3f3f;dis[start][ans]=0;
	dis[start][ans]=0;q.push(make_pair(0,start));
	while(!q.empty()){
		int temp=q.top().second;q.pop();
		if(vis[temp]) continue;
		vis[temp]=1;
		for(int i=head[temp];i;i=edge[i].prev){
			int to=edge[i].to;
			if(dis[to][ans]>dis[temp][ans]+edge[i].w){
				dis[to][ans]=dis[temp][ans]+edge[i].w;
				q.push(make_pair(-dis[to][ans],to));
			}
		}
	}
}
inline void csh(){
	dijkstra(x1);dijkstra(y11);dijkstra(x2);dijkstra(y22);
}
int arrive[2000],dp[2000];
inline void solve(){
	csh();
	fp(i,1,cnt){
		int from=edge[i].from,to=edge[i].to;
		if(dis[from][1]+edge[i].w+dis[to][2]==dis[y11][1]){
			adds(from,to,edge[i].w);
			if(dis[from][3]+edge[i].w+dis[to][4]==dis[y22][3]||dis[from][4]+edge[i].w+dis[to][3]==dis[y22][3]){
				e[h].flag=1;
			}
			arrive[to]++;
		}
	}
	queue<int> q;
	q.push(x1);
	while(!q.empty()){
		int temp=q.front();q.pop();
		for(int i=he[temp];i;i=e[i].prev){
			int to=e[i].to;arrive[to]--;
			dp[to]=max(dp[to],dp[temp]+e[i].w*e[i].flag);
			if(!arrive[to]) q.push(to);
		}
	}
	out(dp[y11]),putchar('\n');
}
int main(){
	start();
	solve();
	return 0;
}
