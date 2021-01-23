#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct Node{
	int num,l,r,lazy;
}node[N<<1];
int n,m,r,p,ans,
    a[N],
	f[N],d[N],size[N],son[N],
	top[N],pre[N],id[N];
vector<int> G[N];

inline void dfs1(int x,int from){
	size[x]=1;
	for(auto to:G[x]){
		if(to==from) continue;
		d[to]=d[x]+1;
		f[to]=x;
		dfs1(to,x);
		size[x]+=size[to];
		if(size[son[x]]<size[to]) son[x]=to; 
	}
}

inline void dfs2(int x,int from){
	top[x]=from;pre[id[x]=++ans]=x;
	if(son[x]) dfs2(son[x],from);
	for(auto to:G[x]){
		if(to==f[x]||to==son[x]) continue;
		dfs2(to,to);
	}
}

inline void pushup(int index){node[index].num=node[index<<1].num+node[index<<1|1].num;} 

inline void pushdown(int index){
	if(node[index].lazy){
		node[index<<1].lazy=node[index<<1|1].lazy=node[index].lazy;
		node[index<<1].num=(node[index<<1].num+node[index].lazy*(
		node[index<<1].r-node[index<<1].l+1));
		node[index<<1|1].num=(node[index<<1|1].num+node[index].lazy*(
		node[index<<1|1].r-node[index<<1|1].l+1));
		node[index].lazy=0;
	}
}

inline void build(int index,int l,int r){
	node[index].l=l;node[index].r=r;
	if(l==r){return node[index].num=a[pre[l]],void();}
	int mid=(l+r)/2;
	build(index<<1,l,mid);
	build(index<<1|1,mid+1,r);
	pushup(index);
}

inline void update(int index,int l,int r,int num){
	if(node[index].l>r||node[index].r<l) return;
	if(node[index].l>=l&&node[index].r<=r){
		node[index].num=(node[index].num+(node[index].r-node[index].l+1)*num)%p;
		node[index].lazy=(node[index].lazy+num)%p;
		return;
	}
	pushdown(index);
	update(index<<1,l,r,num);
	update(index<<1|1,l,r,num);
	pushup(index);
}

inline int querysum(int index,int l,int r){
	if(node[index].l>r||node[index].r<l) return 0;
	if(node[index].l>=l&&node[index].r<=r) return node[index].num%p;
	pushdown(index);
	return (querysum(index<<1,l,r)+querysum(index<<1|1,l,r))%p;
}

inline void path_update(int u,int v,int num){
	while(top[u]!=top[v]){
		if(d[top[u]]<d[top[v]]) swap(u,v);
		update(1,id[u],id[top[u]],num);
		u=f[top[u]];
	}
	if(d[u]<d[v]) swap(u,v);
	update(1,id[v],id[u],num);
}

inline int path_sum(int u,int v){
	int cnt=0;
	while(top[u]!=top[v]){
		if(d[top[u]]<d[top[v]]) swap(u,v);
		cnt=(cnt+querysum(1,id[u],id[top[u]]))%p;
		u=f[top[u]];
	}
	if(d[u]<d[v]) swap(u,v);
	cnt=(cnt+querysum(1,id[v],id[u]))%p;
	return cnt;
}

inline void childtree_update(int x,int num){update(1,id[x],id[x]+size[x]-1,num);}

inline int childtree_sum(int x){return querysum(1,id[x],id[x]+size[x]-1);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>r>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	for(int i=1,fl,x,y,z;i<=m;i++){
		cin>>fl;
		if(fl==1){
			cin>>x>>y>>z;
			path_update(x,y,z);
		}else if(fl==2){
			cin>>x>>y;
			cout<<path_sum(x,y)<<endl;
		}else if(fl==3){
			cin>>x>>z;
			childtree_update(x,z);
		}else{
			cin>>x;
			cout<<childtree_sum(x)<<endl;
		}
	}
	return 0;
}
