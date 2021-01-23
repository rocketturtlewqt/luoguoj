#include <cstdio>
#include <algorithm>
#include<iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std; 
const int MAXN = 105;
const int INF = 1<<30; 
struct Edge{    int to, cap;};
int n,m,s,t, np,nc;
vector<Edge> edge;
vector<int>  G[MAXN];
int d[MAXN], cur[MAXN];
void AddEdge(int from, int to, int cap)
{    
    edge.push_back((Edge){to, cap}); 
    edge.push_back((Edge){from, 0});    
    int id = edge.size();   
	G[from].push_back(id-2);    
	G[to].push_back(id-1);
} 
bool bfs()
{    
    memset(d, 0, sizeof(d));    
	queue<int> Q;    
	Q.push(s);    
	d[s] = 1;    
	while(!Q.empty())    
	{        
	    int x = Q.front(); Q.pop();        
		if(x == t) return true;        
		for(int i=0; i<G[x].size(); i++)        
		{            
		    Edge& e = edge[G[x][i]];            
			if(!d[e.to] && e.cap>0)           
			{                
			    d[e.to] = d[x]+1;                
				Q.push(e.to);            
			}        
		}    
	}    
	return false;
} 
int dfs(int x, int a)
{    
    if(x == t || a == 0) return a;    
	int flow = 0, f;    
	for(int& i=cur[x]; i<G[x].size(); i++)    
	{        
	    Edge& e = edge[G[x][i]];        
		if(d[x]+1 == d[e.to] && (f=dfs(e.to, min(a, e.cap)))>0)        
		{            
		    e.cap -= f;            
			edge[G[x][i]^1].cap += f;           
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
int main()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w);
	}
	cout<<Maxflow();
	return 0;
}
