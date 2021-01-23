#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int to,w,next;
}edge[2000001];
int head[2000001],cnt;
inline void add(int x,int y,int w){
	edge[++cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
int n;
inline void start(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);add(y,x,w);
	}
}
int sum[2000001];
inline void dfs(int now,int fa){
	for(int i=head[now];i;i=edge[i].next){
		int to=edge[i].to;
		int w=edge[i].w;
		if(to!=fa){
			sum[to]=sum[now]^w;
			dfs(to,now);
		}
	}
}
struct Trie{
	int bit[2];
}trie[2000001];
int tot;
inline void build(int node,int w){
	for(int i=(1<<30);i;i>>=1){
		bool num=w&i;
		if(!trie[node].bit[num]) trie[node].bit[num]=++tot;
		node=trie[node].bit[num];
	}
}
inline int query(int node,int w){
	int ans=0;
	for(int i=(1<<30);i;i>>=1){
		bool num=w&i;
		if(trie[node].bit[!num]){
			ans+=i;
			node=trie[node].bit[!num];
		}
		else node=trie[node].bit[num];
	}
	return ans;
}
int main(){
	start();
	dfs(1,-1);
	for(int i=1;i<=n;i++) build(0,sum[i]);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,query(0,sum[i]));
	printf("%d\n",ans);
	return 0;
}
