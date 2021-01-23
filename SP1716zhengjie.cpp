#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,h;

struct node{
    int l,r,sum,dat,lmax,rmax;
}t[maxn*4];

void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        scanf("%d",&h);//省时间又省空间
        t[p].dat=t[p].lmax=t[p].rmax=t[p].sum=h;
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
    t[p].lmax=max(t[p<<1].lmax,t[p<<1].sum+t[p<<1|1].lmax);
    t[p].rmax=max(t[p<<1|1].rmax,t[p<<1|1].sum+t[p<<1].rmax);
    t[p].dat=max(t[p<<1].dat,max(t[p<<1|1].dat,t[p<<1].rmax+t[p<<1|1].lmax));
}

void change(int p,int x,int y){//x为要改的坐标，y为要改成的数
    if(t[p].l==x&&t[p].r==x){
        t[p].dat=t[p].lmax=t[p].rmax=t[p].sum=y;
        return;
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(mid<x) change(p<<1|1,x,y);
    else change(p<<1,x,y);
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
    t[p].lmax=max(t[p<<1].lmax,t[p<<1].sum+t[p<<1|1].lmax);
    t[p].rmax=max(t[p<<1|1].rmax,t[p<<1|1].sum+t[p<<1].rmax);
    t[p].dat=max(t[p<<1].dat,max(t[p<<1|1].dat,t[p<<1].rmax+t[p<<1|1].lmax));
}

node ask(int p,int l,int r){//[l,r]询问的区间
    if(t[p].l>=l&&t[p].r<=r){
        return t[p];
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(mid<l)return ask(p<<1|1,l,r);
    else if(mid>=r)return ask(p<<1,l,r);
    else{
        node a,b;
        a=ask(p<<1,l,r);
        b=ask(p<<1|1,l,r);
        node ttt;
        ttt.dat=max(max(a.dat,b.dat),a.rmax+b.lmax);
        ttt.lmax=max(a.lmax,a.sum+b.lmax);
        ttt.rmax=max(b.rmax,a.rmax+b.sum);
        return ttt;
    }
}

int main(){
    scanf("%d",&n);
    build(1,1,n);
    scanf("%d",&m);
    int a,x,y;
    while(m--){
        scanf("%d%d%d",&a,&x,&y);
        if(a==0){
            change(1,x,y);
        }else{
            if(x>y) swap(x,y);
            node ans=ask(1,x,y);
            printf("%d\n",ans.dat);
        }
    }
    return 0;
}
