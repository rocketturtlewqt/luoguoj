#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1201
using namespace std;
struct Edge{
	int to,w;
};
vector<Edge> edge;
vector<int> G[maxn];
inline int read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a)
{
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
void add(int from,int to,int w)
{
	edge.push_back((Edge){to,w});
	edge.push_back((Edge){from,0});
	int id=edge.size();
	G[from].push_back(id-2);
	G[to].push_back(id-1);
}
int n,m,s,t;
#define fp(i,w,n) for(int i=w;i<=n;i++)
#define fd(i,w,n) for(int i=w;i<n;i++)
inline void start()
{
	n=read(),m=read(),s=read(),t=read();
	fp(i,1,m){
		int u,v,w;
		u=read(),v=read(),w=read();
		add(u,v,w);
	}
}
int deep[maxn];
inline int bfs()
{
	queue<int> q;
    memset(deep,0,sizeof(deep));
    q.push(s),deep[s]=1;
    while(!q.empty())
    {
    	int temp=q.front();q.pop();
    	if(temp==t) return 1;
    	fd(i,0,G[temp].size())
    	{
    		struct Edge &e=edge[G[temp][i]];
    		int to=e.to;
    		if(!deep[to]&&e.w>0){
    			deep[to]=deep[temp]+1;q.push(to);
			}
		}
	}
	return 0;
}
int cur[maxn];
int dfs(int x,int a)
{
	if(x==t||a==0) return a;
	int flow=0,f;
    for(int &i=cur[x];i<G[x].size();i++)
	{
		struct Edge &e=edge[G[x][i]];
		int to=e.to;
		if(deep[to]==deep[x]+1&&(f=dfs(to,min(e.w,a)))>0){
			e.w-=f,edge[G[x][i]^1].w+=f,a-=f,flow+=f;
			if(a==0) break;
		}
	}
	return flow;
}
inline void solve()
{
	int max_flow=0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		max_flow+=dfs(s,0x3f3f3f3f);
	}
    out(max_flow),putchar('\n');
}
int main()
{
	start();
	solve();
}
