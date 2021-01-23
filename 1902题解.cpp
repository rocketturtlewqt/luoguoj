
#include<bits/stdc++.h>
#define IL inline
#define RI register int
#define mod 100000
IL void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
    while(s<='9'&&s>='0'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int n,m,p[1008][1008],tm;
const int ax[]={0,1,0,-1};
const int ay[]={1,0,-1,0};
bool flg,vis[1008][1008];
IL void dfs(int x,int y,int mid)
{
    if(x==n)
    {
        flg=1;
        return;
    }
    vis[x][y]=true;
    for(RI i=0,xx,yy;i<4;++i)
    {
       xx=x+ax[i],yy=y+ay[i];
        if(xx<1 or xx>n or yy<1 or yy>m or vis[xx][yy] or p[xx][yy]>mid)
            continue;
        dfs(xx,yy,mid);
        if(flg)
            return;
    }
}
int main()
{
    read(n),read(m);
    for(RI i=1;i<=n;i++)
        for(RI j=1;j<=m;j++)
            read(p[i][j]);
    int l=0,r=1008;
    while(l<=r)
    {
        int mid=l+r>>1;
        memset(vis,0,sizeof vis);
        flg=false;
        dfs(1,1,mid);
        if(flg==true)
            r=mid-1;
        else l=mid+1;
    }
    printf("%d",l);
}
