#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fp(i,w,n) for(int i=w;i<=n;i++)
#define M 50004
#define N 10000000
inline ll MIN(ll a,ll b){
	if(a<b) return a;
	return b;
}
inline ll MAX(ll a,ll b){
	if(a>b) return b;
	return a;
}
inline int read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a)
{
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
int n,m,tot,b[N];
struct ASK{
	int num,l,r,k;
}q[M];
struct Node{
	int l,r;
}t[N];
inline void start(){
	n=read(),m=read();
	fp(i,1,m) { 
	    q[i].num=read(),q[i].l=read(),q[i].r=read(),q[i].k=read();
        if(q[i].num&1) b[++tot]=q[i].k;
    }
    sort(b+1,b+1+tot);
    tot=unique(b+1,b+1+tot)-b-1;
    fp(i,1,m) if(q[i].num&1)q[i].k=lower_bound(b+1,b+tot+1,q[i].k)-b;
}
inline int len(int l,int r,int L,int R){
	return MIN(r,R)-MAX(l,L)+1;
}
int node,size[N],tag[N];
void update_qujian(int& k,int l,int r,int L,int R){
    if(!k) k=++node; size[k]+=len(L,R,l,r);
    if(L<=l&&r<=R) return ++tag[k],void();
    int mid=(l+r)>>1;
    if(L<=mid) update_qujian(t[k].l,l,mid,L,R);
    if(R>mid) update_qujian(t[k].r,mid+1,r,L,R);
}
int rt[N];
ll get_sum(int k,int l,int r,int L,int R){ int ans=0;
    if(!k) return 0; if(L<=l&&r<=R) return size[k];
    int mid=(l+r)>>1;
    ans+=L<=mid?get_sum(t[k].l,l,mid,L,R):0;
    ans+=R>mid?get_sum(t[k].r,mid+1,r,L,R):0;
    return ans+len(L,R,l,r)*tag[k];
}
void update_quanzhi(int k,int l,int r,int L,int R,ll K){
    update_qujian(rt[k],1,n,L,R); if(l==r) return ;
    int mid=(l+r)>>1;
    if(K<=mid) update_quanzhi(k<<1,l,mid,L,R,K);
    else update_quanzhi(k<<1|1,mid+1,r,L,R,K);
}
ll query(int k,int l,int r,int L,int R,ll K){
    if(l==r) return b[l];
    ll tt=get_sum(rt[k<<1|1],1,n,L,R);
    int mid=(l+r)>>1;
    if(tt<K) return query(k<<1,l,mid,L,R,K);
    else return query(k<<1|1,mid+1,r,L,R,K);
}
inline void solve(int l){
	fp(i,1,m){
		if(q[i].num==1)update_quanzhi(1,1,l,q[i].l,q[i].r,q[i].k);
		else if(q[i].num==2)out(query(1,1,l,q[i].l,q[i].r,q[i].k)),putchar('\n');
	}
}
int main(){
	start();
	solve(tot);
	return 0;
}
