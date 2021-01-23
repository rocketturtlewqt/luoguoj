#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,w;
}edge[300000<<1];
int n,m,cnt,par[10000];
bool compare(struct Edge a,struct Edge b){
	return a.w<b.w;
}
inline int find(int x){
	int r=x;
	while(r!=par[r]){
		r=par[r];
	}
	return par[r];
}
inline void init(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty) par[tx]=ty;
}
inline void start(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) par[i]=i;
	for(int i=1;i<=m;i++) cin>>edge[i].from>>edge[i].to>>edge[i].w;
	sort(edge+1,edge+m+1,compare);
}
int main(){
	int sum=0;
	start();
	for(int i=1;i<=m;i++){
		int u=edge[i].from,v=edge[i].to;
		if(find(u)!=find(v)){
			init(u,v);
			cnt++;
			sum+=edge[i].w;
		}
		if(cnt==n-1) break;
	}
	if(cnt<n-1) puts("orz");
	else cout<<sum<<endl;
	return 0;
}
