#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int inf=1<<29,N=50010,M=300010;
int head[N],ver[N],edge[N],Next[N],d[N];
int n,m,s,t,tot,maxflow;
queue<int>q;
void add(int x,int y,int z)
{
	ver[++tot]=y;edge[tot]=z;Next[tot]=head[x];head[x]=tot;
	ver[++tot]=x;edge[tot]=0;Next[tot]=head[y];head[y]=tot;
}
bool bfs()//在残量网络上构造分层图 
{
	memset(d,0,sizeof(d));
	while(q.size())q.pop();
	q.push(s);d[s]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=Next[i])
		    if(edge[i]&&!d[ver[i]])
		    {
		    	q.push(ver[i]);
		    	d[ver[i]]=d[x]+1;
		    	if(ver[i]==t)return 1;
			}
	}
	return 0;
}
int dinic(int x,int flow)//在当前分层图上增广 
{
	if(x==t)return flow;
	int rest=flow,k;
	for(int i=head[x];i;i=Next[i])
	    if(edge[i]&&d[ver[i]]==d[x]+1){
	    	k=dinic(ver[i],min(rest,edge[i]));
	    	if(!k)d[ver[i]]=0;
	    	edge[i]-=k;
	    	edge[i^1]+=k;
	    	rest-=k;
		}
	return flow-rest;
}
int main()
{
	cin>>n>>m;
	cin>>s>>t;//源点、汇点
	tot=1;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		add(x,y,c);
	}
	int flow=0;
	while(bfs()){
	    while(flow=dinic(s,inf))maxflow+=flow;
	}
	cout<<maxflow<<endl;
}

