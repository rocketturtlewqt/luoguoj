#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 200001
using namespace std;
int n,m,cnt,ans,sum;
double p,h;
int vis[5001],head1[5001],head2[5001];
double dis[5001];
struct Edge
{
	int to;
	double w;
	int prev;
}edge1[maxium],edge2[maxium];
struct Node
{
	int to;
	double f;
	double g;
	bool operator<(const Node &r) const
	{
		if(r.f==f) return r.g<g;
		return r.f<f;
	}
};
void add(int x,int y,double w)
{
	edge1[++cnt].to=y;
	edge1[cnt].w=w;
	edge1[cnt].prev=head1[x];
	head1[x]=cnt;
	edge2[++ans].to=x;
	edge2[ans].w=w;
	edge2[ans].prev=head2[y];
	head2[y]=ans;
}
void start()
{
	scanf("%d%d%lf",&n,&m,&p);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		double w;
		scanf("%d%d%lf",&u,&v,&w);
		add(u,v,w);
	}
}
void spfa()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
	dis[i]=0x3f3f3f3f;
	dis[n]=0;
	q.push(n);vis[n]=1;
	while(!q.empty())
	{
		int temp=q.front();q.pop();vis[temp]=0;
		for(int i=head2[temp];i;i=edge2[i].prev)
		{
			int to=edge2[i].to;
			if(dis[to]>dis[temp]+edge2[i].w)
			{
				dis[to]=dis[temp]+edge2[i].w;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
void A_star()
{
	priority_queue<Node> que;
	struct Node e,ne;
	e.to=1;e.g=0;e.f=e.g+dis[1];
	que.push(e);
	while(!que.empty())
	{
		e=que.top();que.pop();
		if(e.to==n) 
		{
			h+=e.f;
			if(h<=p) sum++;
			else return;
		}
		for(int i=head1[e.to];i;i=edge1[i].prev)
		{
			ne.to=edge1[i].to;
			ne.g=e.g+edge1[i].w;
			ne.f=ne.g+dis[ne.to];
			que.push(ne);
		}
	}
}
void solve()
{
	spfa();	
	A_star();
	cout<<sum;
}
int main()
{
	start();
	solve();
	return 0;
}
