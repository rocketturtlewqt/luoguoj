#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAX 100100
#define lson (now<<1)
#define rson (now<<1|1)
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}
int N=100000;
struct Node
{
    bool fl;int id;double k,b;
    void upd(int _id,double _k,double _b){id=_id,k=_k;b=_b;}
}t[MAX<<2];
double K[MAX],B[MAX];
void Modify(int now,int l,int r,int id,double k,double b)
{
	//如果这个区间没有记录最长的线段，那么直接把这个区间记录的线段修改为这条线段，然后返回。
    if(!t[now].fl){t[now].fl=true;t[now].upd(id,k,b);return;}
    int mid=(l+r)>>1;
    double l1=l*t[now].k+t[now].b,r1=r*t[now].k+t[now].b;
    double l2=l*k+b,r2=r*k+b;
    //如果当前线段在这个区间内已经被这个区间内的最长线段为覆盖，那么直接gg，返回就好了。
    if(l1>=l2&&r1>=r2)return;
    //反过来，如果完全覆盖了之前记录的线段，那么直接赋值、返回。
    if(l2>l1&&r2>r1){t[now].upd(id,k,b);return;}
    //否则和已经记录的直线有交，判断哪根线段覆盖的区域较长，把这个区间记录的值给修改一下，然后把短的那一半丢下去递归
    double x=(t[now].b-b)/(k-t[now].k);
    if(x<=mid)
    {
        if(l1>l2)Modify(lson,l,mid,t[now].id,t[now].k,t[now].b),t[now].upd(id,k,b);
        else Modify(lson,l,mid,id,k,b);
    }
    else
    {
        if(l1>l2)Modify(rson,mid+1,r,id,k,b);
        else Modify(rson,mid+1,r,t[now].id,t[now].k,t[now].b),t[now].upd(id,k,b);
    }
}
void Modify(int now,int l,int r,int L,int R,int id,double k,double b)
{
    if(L<=l&&r<=R){Modify(now,l,r,id,k,b);return;}
    int mid=(l+r)>>1;
    if(L<=mid)Modify(lson,l,mid,L,R,id,k,b);
    if(R>mid)Modify(rson,mid+1,r,L,R,id,k,b);
}
void Cmax(int &a,int b,int x)
{
    double ya=K[a]*x+B[a];
    double yb=K[b]*x+B[b];
    if(ya<yb||(fabs(ya-yb)<1e-7&&a>b))a=b;
}
int Query(int now,int l,int r,int x)
{
    if(l==r)return t[now].id;
    int mid=(l+r)>>1,ret=t[now].id;
    if(x<=mid)Cmax(ret,Query(lson,l,mid,x),x);
    else Cmax(ret,Query(rson,mid+1,r,x),x);
    return ret;
}
int Q,ans,tot;
int main()
{
    Q=read();
    while(Q--)
    {
        int opt=read();
        if(!opt)
        {
            int x=((read()+ans-1)%39989+1);
            ans=Query(1,1,N,x);
            printf("%d\n",ans);
        }
        else
        {
            int x0=(read()+ans-1)%39989+1,y0=(read()+ans-1)%1000000000+1;
            int x1=(read()+ans-1)%39989+1,y1=(read()+ans-1)%1000000000+1;
            if(x0>x1)swap(x0,x1),swap(y0,y1);
            ++tot;K[tot]=1.0*(y0-y1)/(x0-x1);B[tot]=y0-K[tot]*x0;
            Modify(1,1,N,x0,x1,tot,K[tot],B[tot]);
        }
    }
    return 0;
}
