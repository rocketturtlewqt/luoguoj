#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f3f;

struct Edge{
	int u,v,z;
	bool operator<(const Edge &x)const{
	    return z>x.z;
	}
}edge[N];
struct Node{
	int num,l,r;
}node[N];
int n,m,ans,q,u,v,
    head[N],fa[N],a[N],
	d[N],son[N],size[N],f[N],
	top[N],id[N],pre[N];
vector<pair<int,int> > G[N];

inline void add(int x,int y,int z){
	G[x].push_back({y,z});
	G[y].push_back({x,z});
}

inline int find(int x){
    return x==fa[x]?fa[x]:(fa[x]=find(fa[x]));
}

inline void kruscal(){
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;i++){
		int x=edge[i].u,
		    y=edge[i].v,
		    z=edge[i].z,
		    tx=find(x),
		    ty=find(y);
		if(tx!=ty) fa[tx]=ty,add(x,y,z),ans++;
		if(ans>n-1) break;
	}
}

inline void dfs1(int x,int from){
	size[x]=1;
	for(auto t:G[x]){
		int to=t.first,
		    w=t.second;
		if(to==from) continue;
		f[to]=x;
		d[to]=d[x]+1;
		a[to]=w;
		dfs1(to,x); 
		size[x]+=size[to];
		if(size[son[x]]<size[to]) son[x]=to;
	}
} 

inline void dfs2(int x,int from){
	pre[id[x]=++ans]=x;top[x]=from;
	if(son[x]) dfs2(son[x],from);
	for(auto t:G[x]){
		int to=t.first;
		if(to==f[x]||to==son[x]) continue;
		dfs2(to,to);
	}
}

inline void pushup(int index){node[index].num=min(node[index<<1].num,node[index<<1|1].num);}

inline void build(int index,int l,int r){
	node[index].l=l;node[index].r=r;
	if(l==r) return node[index].num=a[pre[l]],void();
	int mid=(l+r)/2;
	build(index<<1,l,mid);
	build(index<<1|1,mid+1,r);
	pushup(index);
}

inline int querymin(int index,int l,int r){
	if(node[index].l>r||node[index].r<l) return inf;
	if(node[index].l>=l&&node[index].r<=r) return node[index].num;
	return min(querymin(index<<1,l,r),querymin(index<<1|1,l,r));
}

inline int qmin(int u,int v){
	int ans=inf;
	while(top[u]!=top[v]){
		if(d[top[u]]<d[top[v]]) swap(u,v);
		ans=min(ans,querymin(1,id[top[u]],id[u]));
		u=f[top[u]];
	}
	if(d[u]<d[v]) swap(u,v);
	ans=min(ans,querymin(1,id[v]+1,id[u]));
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(a,-1,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	    cin>>edge[i].u>>edge[i].v>>edge[i].z;
	kruscal();
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--){
		cin>>u>>v;
	    int tu=find(u),
	        tv=find(v);
	    if(tu!=tv) cout<<-1<<endl;
	    else cout<<qmin(u,v)<<endl;
	}
	return 0;
}
/*
10 24
4 7 19038
7 10 7375
7 9 17853
9 8 6341
7 2 16976
10 3 2835
10 4 19285
9 4 29193
3 4 4852
3 8 16597
9 1 4138
9 7 21611
7 4 10586
10 4 7821
10 9 25636
3 9 28425
2 3 17229
4 8 11331
9 2 25053
6 4 929
8 3 1738
10 9 28542
1 2 28343
3 5 13215
9
7 5
2 4
10 2
5 10
7 10
4 3
10 1
10 4
8 4
*/
