#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
int n,cnt,a[MAXN],head[MAXN],par[MAXN],dp[MAXN];
vector<int> son[17000];
struct Edge{
	int to,prev;
}edge[MAXN];
inline void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void dfs(int x){
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(par[x]==to) continue;
		par[to]=x;
		dfs(to);
		son[x].push_back(to);
	}
}
inline void f(int x){
	dp[x]=a[x];
	for(int i=0;i<son[x].size();i++){
		int so=son[x][i];
		f(so);
		dp[x]=max(dp[x],dp[x]+dp[so]);
	}
}
inline void start(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		add(u,v);add(v,u);
	}
}
int main(){
	int maxx=-0x3f3f3f3f;
	start();dfs(1);f(1);
    for(int i=1;i<=n;i++) maxx=max(maxx,dp[i]);
    return cout<<maxx<<endl,0;
}
