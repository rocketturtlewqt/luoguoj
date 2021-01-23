#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scfff(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
const int MAXN=1e4+5;
struct Edge{
	int to,w,prev;
}edge[MAXN*20];
int n,m,s,t,cnt,maxflow,d[MAXN],head[MAXN];
queue<int> q;
inline void add(int x,int y,int w){
	edge[++cnt].to=y;edge[cnt].w=w;edge[cnt].prev=head[x];head[x]=cnt;
	edge[++cnt].to=x;edge[cnt].w=0;edge[cnt].prev=head[x];head[x]=cnt;
}
inline int bfs(){
	memset(d,0,sizeof(d));
	while(q.size()) q.pop();
	q.push(s);d[s]=1;
	while(q.size()){
		int tmp=q.front();q.pop();
		for(int i=head[tmp];i;i=edge[i].prev){
			int to=edge[i].to;
			if(edge[i].w&&!d[to]){
				d[to]=d[tmp]+1;
				q.push(to);
				if(to==t) return 1;
			}
		}
	}
	return 0;
}
inline int dinic(int x,int flow){
	if(x==t) return flow;
	int rest=flow,k;
	for(int i=head[x];i&&rest;i=edge[i].prev){
		int to=edge[i].to;
		if(edge[i].w&&d[to]==d[x]+1){
			k=dinic(to,min(rest,edge[i].w));
			if(!k) d[to]=0;
			edge[i].w-=k;
			edge[i^1].w+=k;
			rest-=k;
		}
	}
	return flow-rest;
}
int main(){
	scfff(n,m,s,t);cnt=1;
	fp(i,1,m){
		int u,v,w;
		scff(u,v,w);
		add(u,v,w);
	}
	int flow=0;
    while(bfs()){
    	while(flow=dinic(s,0x3f3f3f3f)) maxflow+=flow;
	}
	return printf("%d\n",maxflow),0;
}
/*
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#define maxium 10020
using namespace std;
int n,m,s,t;
int cur[maxium],deep[maxium];
struct Edge{
	int to;
	int w;
};
vector<Edge> edge;
vector<int> G[maxium];
void add(int from,int to,int w)
{
	edge.push_back((Edge){to,w});
	edge.push_back((Edge){from,0});
	int id=edge.size();
	G[from].push_back(id-2);
	G[to].push_back(id-1);
}
void start()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
}
int bfs()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(deep,0,sizeof(deep));
	q.push(s);deep[s]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
		if(temp==t) return 1;
		for(int i=0;i<G[temp].size();i++)
		{
			struct Edge& e=edge[G[temp][i]];
			if(!deep[e.to]&&e.w>0)
			{
				deep[e.to]=deep[temp]+1;
				q.push(e.to);
			}
		}
	}
	return 0;
}
int dfs(int x, int a)
{    
    if(x == t || a == 0) return a;    
	int flow = 0, f;    
	for(int& i=cur[x]; i<G[x].size(); i++)    
	{        
	    Edge& e = edge[G[x][i]];        
		if(deep[x]+1 == deep[e.to] && (f=dfs(e.to, min(a, e.w)))>0)        
		{            
		    e.w -= f;            
			edge[G[x][i]^1].w += f;           
			flow += f;            
			a -= f;            
			if(a == 0) break;        
		}    
	}    
	return flow;
} 
int Maxflow()
{    
    int flow = 0;    
	while(bfs())    
	{        
	    memset(cur, 0, sizeof(cur));        
		flow += dfs(s, 0x3f3f3f3f);    
	}    
	return flow;
}
void solve()
{
	cout<<Maxflow();
}
int main()
{
	start();
	solve();
	return 0;
}
*/
