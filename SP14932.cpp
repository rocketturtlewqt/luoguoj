#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,par[10000];
inline void start(){
	cin>>T;
}
int head1[10000],head2[10000],vis[10000],cnt,ans;
struct Edge{
	int to,prev;
}edge[10000000];
struct ASK{
	int from,to,prev;
}ask[10000000];
inline void addedge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].prev=head1[x];
	head1[x]=cnt;
}
inline void addask(int x,int y)
{
	ask[++ans].to=y;
	ask[ans].from=x;
	ask[ans].prev=head2[x];
	head2[x]=ans;
}
inline int find(int x){
	int r=x;
	while(r!=par[r])
	{
		r=par[r];
	}
	return par[r];
}
inline void init(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty) par[tx]=ty;
}
int f[10000],node[10000000];
inline void lca(int x)
{
	for(int i=head1[x];i;i=edge[i].prev){
		int to=edge[i].to;if(to==f[x]) continue;f[to]=x;
		lca(to);
		init(to,x);
		vis[to]=1;
	}
	for(int i=head2[x];i;i=ask[i].prev){
		int to=ask[i].to;
		if(vis[to]) node[i]=find(to);
	}
}
inline void solve(){
	int h=0;
	while(T--){
		memset(head1,0,sizeof(head1));
		memset(head2,0,sizeof(head2));
		memset(vis,0,sizeof(vis));
		memset(node,0,sizeof(node));
		cnt=ans=0;
		int n;cin>>n;
		for(int i=1;i<=n;i++) f[i]=i,par[i]=i;
		for(int i=1;i<=n;i++){
			int m;cin>>m;if(!m) continue;
			for(int j=1;j<=m;j++){
				int p;cin>>p;addedge(i,p);addedge(p,i);
			}
		}
		int query;cin>>query;
		for(int i=1;i<=query;i++){
			int x,y;cin>>x>>y;if(x==y) node[i*2-1]=node[i*2]=x;addask(x,y);addask(y,x);
		}
		lca(1);
	    printf("Case %d:\n",++h);
		for(int i=1;i<=query;i++){
            printf("%d\n",max(node[2*i],node[2*i-1]));
		}
	}
}
int main(){
	start();
	solve();
	return 0;
}

