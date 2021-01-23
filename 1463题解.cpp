#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 1000000
struct node{
    int l,r,f,sum;
}tr[MAXN];
int s[MAXN],su[MAXN];
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }while(ch>=48&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }return s*w;
}
void build(int l,int r,int k){
    tr[k].l=l;
    tr[k].r=r;
    if(l==r){
        tr[k].sum=0;
        return;
    }int mid=(l+r)>>1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void pushdown(int x){
    tr[x<<1].f+=tr[x].f;
    tr[x<<1|1].f+=tr[x].f;
    tr[x<<1].sum+=tr[x].f*(tr[x<<1].r-tr[x<<1].l+1);
    tr[x<<1|1].sum+=tr[x].f*(tr[x<<1|1].r-tr[x<<1|1].l+1);
    tr[x].f=0;
}
int query(int li,int ri,int x){
    if(tr[x].l>=li&&tr[x].r<=ri)return tr[x].sum;
    pushdown(x);
    int mid=(tr[x].l+tr[x].r)>>1;
    if(li<=mid&&mid<ri)return query(li,ri,x<<1)+query(li,ri,x<<1|1);
    else if(li<=mid)return query(li,ri,x<<1);
    else return query(li,ri,x<<1|1);
}
void add(int li,int ri,int x,int val){
    if(tr[x].l>=li&&tr[x].r<=ri){
        tr[x].sum+=val*(tr[x].r-tr[x].l+1);
        tr[x].f+=val;
        return;
    }pushdown(x);
    int mid=(tr[x].l+tr[x].r)>>1;
    if(li<=mid)add(li,ri,x<<1,val);
    if(mid<ri)add(li,ri,x<<1|1,val);
    tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++)s[i]=read();
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int opt=read();
        if(opt==1){
            int L=read(),R=read(),K=read(),D=read();
            add(L,L,1,K);
            if(R>L)add(L+1,R,1,D);
            int N=(R-L+1);
            if(R<n)add(R+1,R+1,1,-(K+(N-1)*D));
        }else{
            int wq=read();
            cout<<(s[wq]+query(1,wq,1))<<endl;
        }
    }
    for(int i=1;i<=9;i++)
	printf("%d %d %d %d\n",i,tr[i].l,tr[i].r,tr[i].sum);
    return 0;
}
