#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=4e6+5;
struct Tree{
	int l,r,size;
}node[MAXN];
int n,m,k,a[MAXN],b[MAXN],root[MAXN];
inline int clone(int prev){
	int now=++k;
	node[now]=node[prev];
	node[now].size++;
	return now;
}
inline int build(int l,int r){
	int now=++k;
	if(l<r){
		int mid=(l+r)>>1;
	    node[now].l=build(l,mid);
		node[now].r=build(mid+1,r);
	}
	return now;
}
inline int update(int prev,int l,int r,int x){
	int now=clone(prev);
	if(l<r){
	    int mid=(l+r)>>1;
	    if(x<=mid) node[now].l=update(node[prev].l,l,mid,x);
	    else node[now].r=update(node[prev].r,mid+1,r,x);
	}
	return now; 
}
inline int query(int now,int prev,int l,int r,int x){
	if(l==r) return l;
	int size=node[node[now].l].size-node[node[prev].l].size;
	if(l<r){
	    int mid=(l+r)>>1;
	    if(x<=size) return query(node[now].l,node[prev].l,l,mid,x);
	    else return query(node[now].r,node[prev].r,mid+1,r,x-size);
	}
}
int main(){
	scf(n,m);
	fp(i,1,n) sc(a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int ans=unique(b+1,b+n+1)-b-1;
	root[0]=build(1,ans);
	fp(i,1,n){
		int pos=lower_bound(b+1,b+ans+1,a[i])-b;
		root[i]=update(root[i-1],1,ans,pos);
	}
	fp(i,1,m){
		int l,r,h;
		cin>>l>>r>>h;
		printf("%d\n",b[query(root[r],root[l-1],1,ans,h)]);
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
const int MAXN=2e6+5;
struct Node{
	int id,num;
	bool operator<(const Node &b)const{
	    return num<b.num;
	}
}a[MAXN];
struct Tree{
	int l,r,size;
}node[MAXN<<4];
int n,m,N,k,u,v,h,b[MAXN],ys[MAXN],root[MAXN];
inline void start(){
	scf(n,m);fp(i,1,n) sc(a[i].num),a[i].id=i;
}
inline void lsh(){
	b[a[1].id]=++N;ys[N]=a[1].num;
	fp(i,2,n){
		if(a[i].num!=a[i-1].num) N++;
		b[a[i].id]=N;ys[N]=a[i].num;
	}
}
inline int clone(int prev){
	int now=++k;
	node[now]=node[prev];
	node[now].size++;
	return now;
}
inline int build(int l,int r){
	int now=++k;
	if(l<r){
	    int mid=(l+r)>>1;
	    node[now].l=build(l,mid);
	    node[now].r=build(mid+1,r);
	}
	return now;
}
inline int update(int prev,int l,int r,int pos){
	int now=clone(prev);
	if(l<r){
		int mid=(l+r)>>1;
		if(pos<=mid) node[now].l=update(node[prev].l,l,mid,pos);
		else node[now].r=update(node[prev].r,mid+1,r,pos);
	}
	return now;
}
inline int query(int now,int prev,int l,int r,int x){
	if(l==r) return l;
	int size=node[node[now].l].size-node[node[prev].l].size;
	if(l<r){
		int mid=(l+r)>>1;
		if(x<=size) query(node[now].l,node[prev].l,l,mid,x);
		else query(node[now].r,node[prev].r,mid+1,r,x-size);
	}
}
inline void solve(){
	sort(a+1,a+n+1);
	lsh();
	root[0]=build(1,N);
	fp(i,1,n) root[i]=update(root[i-1],1,N,b[i]);
	fp(i,1,m){
		scanf("%d%d%d",&u,&v,&h);
		printf("%d\n",ys[query(root[v],root[u-1],1,N,h)]);
	}
}
int main(){
	start();
    solve();
    return 0;;
}
*/
