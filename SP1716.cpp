#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5*1e5+5;
struct Node{
	ll num,start,end,lmax,rmax,dat;
}node[MAXN<<4];
ll n,q;
inline void pushup(ll index){
	node[index].num=node[index<<1].num+node[index<<1|1].num;
	node[index].lmax=max(node[index<<1].lmax,node[index<<1].num+node[index<<1|1].lmax);
	node[index].rmax=max(node[index<<1|1].rmax,node[index<<1|1].num+node[index<<1].rmax);
	node[index].dat=max(max(node[index<<1].dat,node[index<<1|1].dat),node[index<<1].rmax+node[index<<1|1].lmax);
}
inline void build(ll index,ll start,ll end){
	node[index].start=start;node[index].end=end;
    if(start==end){
    	scanf("%lld",&node[index].num);
    	node[index].lmax=node[index].num;
    	node[index].rmax=node[index].num;
    	node[index].dat=node[index].num;
    	return void();
	}
	ll mid=(start+end)/2;
	build(index<<1,start,mid);
	build(index<<1|1,mid+1,end);
	pushup(index);
}
inline void update(ll index,ll x,ll data){
	if(node[index].start==node[index].end&&node[index].start==x){
		node[index].num=node[index].lmax=node[index].rmax=node[index].dat=data;
		return;
	}
	ll mid=(node[index].start+node[index].end)/2;
	if(x>mid) update(index<<1|1,x,data);
	else update(index<<1,x,data);
	pushup(index);
}
inline Node query(ll index,ll start,ll end){
	if(node[index].start>=start&&node[index].end<=end) return node[index];
	ll mid=(node[index].start+node[index].end)/2;
	if(mid<start) return query(index<<1|1,start,end);
	else if(mid>=end) return query(index<<1,start,end);
	else {
		struct Node a,b;
		a=query(index<<1,start,end);
		b=query(index<<1|1,start,end);
		struct Node t;
		t.dat=max(max(a.dat,b.dat),a.rmax+b.lmax);
		t.lmax=max(a.lmax,a.num+b.lmax);
		t.rmax=max(b.rmax,b.num+a.rmax);
		return t;
	}
}
int main(){
	scanf("%lld%lld",&n,&q);
    build(1,1,n);
    for(int i=1;i<=q;i++){
    	ll num,x,y;
    	scanf("%lld",&num);
    	if(num==2){
    		scanf("%lld%lld",&x,&y);
    		update(1,x,y);
//    		for(int i=1;i<=9;i++) printf("%lld %lld %lld %lld %lld\n",node[i].start,node[i].end,node[i].lmax,node[i].rmax,node[i].dat,node[i].num);
		}
		else{
			scanf("%lld%lld",&x,&y);
			if(x>y) swap(x,y);
			struct Node t=query(1,x,y);
			printf("%lld\n",t.dat);
	//		for(int i=1;i<=9;i++) printf("%lld %lld %lld %lld %lld\n",node[i].start,node[i].end,node[i].lmax,node[i].rmax,node[i].dat,node[i].num);
		}
	}
	return 0;
}
 
