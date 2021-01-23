#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(register int i=x;i<=y;++i)
#define repd(i,x,y) for(register int i=x;i>=y;--i)
#define ll long long
using namespace std;
const int N=5e4+7;
const int M=N*400;
ll tr[M],lz[M],C[N],n,m,cnt,rk[N];
int ls[M],rs[M],root[N<<2],A[N],B[N],op[N],len,ct;
template <typename T>inline void read(T &x){
    x=0;char c;int sign=1;
    do{c=getchar(); if(c=='-')sign=-1;}while(c<'0'||c>'9');
    do{x=x*10+c-'0';c=getchar();}while(c>='0'&&c<='9');
    x*=sign;
}
inline void update(int &o,int l,int r,int L,int R){
    if(!o)o=++cnt;
    tr[o]+=min(r,R)-max(l,L)+1;
    if(L<=l&&R>=r){lz[o]++;return ;}
    int mid=l+r>>1;
    if(L<=mid)update(ls[o],l,mid,L,R);
    if(R>mid)update(rs[o],mid+1,r,L,R);
}
inline void UPDATE(int a,int b,int c){
    int l=1,r=len,k=1;
    while(l<r){
        int mid=l+r>>1;
        update(root[k],1,n,a,b);
        if(c<=mid)k<<=1,r=mid;
        else k=k<<1|1,l=mid+1;
    }
    update(root[k],1,n,a,b);
}
inline ll query(int o,int l,int r,int L,int R){
    if(!o)return 0;
    if(L<=l&&R>=r)return tr[o];
    int mid=l+r>>1;ll ans=lz[o]*(min(r,R)-max(L,l)+1);
    if(L<=mid)ans+=query(ls[o],l,mid,L,R);
    if(R>mid)ans+=query(rs[o],mid+1,r,L,R);
    return ans;
}
inline int QUERY(int a,int b,int c){
    int l=1,r=len,k=1;
    while(l<r){
        int mid=l+r>>1;ll t=query(root[k<<1],1,n,a,b);
        if(c<=t)r=mid,k<<=1;
        else l=mid+1,k=k<<1|1,c-=t;
    }
    return l;
}
int main(){
    read(n);read(m);
    rep(i,1,m){read(op[i]);read(A[i]);read(B[i]);read(C[i]);if(op[i]==1)rk[++ct]=C[i];}
    sort(rk+1,rk+ct+1);
    len=unique(rk+1,rk+ct+1)-rk-1;
    rep(i,1,m)if(op[i]==1)C[i]=lower_bound(rk+1,rk+len+1,C[i])-rk;
    rep(i,1,m){
        if(op[i]==1){UPDATE(A[i],B[i],len-C[i]+1);}
        else printf("%d\n",rk[len-QUERY(A[i],B[i],C[i])+1]);
    }
    return 0;
}
