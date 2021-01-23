#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxium 1000050
using namespace std;
int n,m,root,cnt,ans;
int head1[maxium],head2[maxium],vis[maxium],par[maxium],f[maxium],node[maxium];
struct Edge{
	int to;
	int prev;
}edge[maxium];
struct Ask{
	int to;
	int prev;
}ask[maxium];
inline int find(int x){
	if(x==par[x]) return x;
	return par[x]=find(par[x]);
}
inline void init(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty) par[tx]=ty;
}
inline void addedge(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].prev=head1[x];
	head1[x]=cnt;
}
inline void addask(int x,int y){
	ask[++ans].to=y;
	ask[ans].prev=head2[x];
	head2[x]=ans;
}
inline void start(){
	scanf("%d%d%d",&n,&m,&root);
	for(int i=1;i<=n-1;i++){
    	int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,b);addedge(b,a);// 题目要求输入
    }
    for(int i=1;i<=m;i++){
    	int a,b;
        scanf("%d%d",&a,&b);  //题目要求输入，我用邻接表存储询问关系，
        addask(a,b);addask(b,a);  //x,y 的公共祖先与 y,x 的公共祖先是一样的，要存双向 
    }
    for(int i=1;i<=n;i++)   //并查集常规初始化 {
        par[i]=i;
        f[i]=i;
    }
}
inline void lca(int x){
	for(int i=head1[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(to==f[x]) continue;
		f[to]=x;
		lca(to);
		init(to,x);
		vis[to]=1;
	}
	for(int i=head2[x];i;i=ask[i].prev){
		int to=ask[i].to;
		if(vis[to]) {
			node[i]=find(to);
		}
	}
}
void solve(){
	lca(root);
	for(int i=1;i<=m;i++)
	printf("%d\n",max(node[i*2],node[i*2-1]));
}
int main(){
	start();
	solve();
	return 0;
}



