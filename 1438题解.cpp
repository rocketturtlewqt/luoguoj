#include<iostream>
#include<cstdio>
#define ls root<<1,l,mid
#define rs root<<1|1,mid+1,r
#define MAXN 100001

using namespace std;

int n,m;
int s[MAXN],sum[MAXN<<2],lazy[MAXN<<2];

inline void push_up(int root)
{
    sum[root]=sum[root<<1]+sum[root<<1|1];
}

inline void push_down(int root,int len)
{
    if(lazy[root])
    {
        lazy[root<<1]+=lazy[root];
        lazy[root<<1|1]+=lazy[root];
        sum[root<<1]+=(len-(len>>1))*lazy[root];
        sum[root<<1|1]+=(len>>1)*lazy[root];
        lazy[root]=0;
    }
}

inline void update(int root,int l,int r,int L,int R,int val)
{
    if(L<=l && r<=R){sum[root]+=(r-l+1)*val;lazy[root]+=val;return;}
    push_down(root,r-l+1);
    int mid=(l+r)>>1;
    if(mid>=L) update(ls,L,R,val);
    if(mid<R) update(rs,L,R,val);
    push_up(root);
}

inline int query(int root,int l,int r,int L,int R)
{
    if(L<=l && r<=R) return sum[root];
    push_down(root,r-l+1);
    int mid=(l+r)>>1;int total=0;
    if(mid>=L) total+=query(ls,L,R);
    if(mid<R) total+=query(rs,L,R);
    return total;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    int type,L,R,K,D,ask;
    while(m--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>L>>R>>K>>D;
            update(1,1,n,L,L,K);
            if(R>L) update(1,1,n,L+1,R,D);
            int N=R-L+1;
            if(R!=n) update(1,1,n,R+1,R+1,-(K+(N-1)*D));
        }
        else
        {
            cin>>ask;
            printf("%d\n",s[ask]+query(1,1,n,1,ask));
        }
    }
    return 0;
}

