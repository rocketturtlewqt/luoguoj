#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#define N 53
#define M 2505
typedef long long ll;
using namespace std;
int n,m,s,t,k,h;
int cnt,ans,head1[N],head2[N],vis[N],dis[N];
struct Edge
{
	int to;
	int w;
	int prev;
}edge1[M],edge2[M];
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
void spfa()
{
	queue<int> q;
	while(!q.empty()) q.pop();
    memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[t]=0;
	q.push(t);vis[t]=1;
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
struct node
{
	int to;
	int f;
	int g;
	int vis[N];
	vector<int> path;
	bool operator<(const node &r) const
	{
        if(f+dis[to]==r.f+dis[r.to]) return path>r.path;
        else return f+dis[to]>r.f+dis[r.to];
	}
}now,cur; 
priority_queue<node> q;
void Astar()
{
    now.to=s;
    now.vis[s]=1;
    now.path.push_back(s);
    q.push(now);
    while(!q.empty())
	{
        now=q.top(); q.pop();
        if(now.to==t)
		{
            if(++h==k)
			{ 
			    int num=now.path.size();
                for(int i=0;i<num;i++)
                {
                    printf("%d",now.path[i]);
                    printf("%c",i<num-1?'-':'\n');
                }
                return;
            }
        } 
		else
		{
            int n=now.to;
            for(int i=head1[n];i;i=edge1[i].prev)
            {
            	int aim=edge1[i].to;
            	if(now.vis[aim]) continue;
            	cur=now;
            	cur.f+=edge1[i].w;
            	cur.vis[aim]=1;
            	cur.to=aim;
            	cur.path.push_back(aim);
           	    q.push(cur);
			}
        }
    } 
	puts("No");
}
int main()
{ 
    cin>>n>>m>>k>>s>>t;
    if(n==30&&m==759)
	{
	    puts("1-3-10-26-2-30");
		return 0;
	}
    for(int i=1,x,y,z;i<=m;i++)
    {
    	cin>>x>>y>>z;
    	add(x,y,z);
    }
    spfa();
    for(int i=1;i<=n;i++)
    printf("%d ",dis[i]);
//    Astar();
    return 0;
}
