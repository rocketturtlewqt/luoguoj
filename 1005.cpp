#include<bits/stdc++.h>
typedef long long ll;
int n,m;
ll ans=0;
int a[100]={0};
ll f[100][100];
ll p[100]={1};

ll dp()
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        for(int j=m;j>=i;j--)
        {
            f[i][j]=std::max( f[i-1][j]+ p[m-j+i-1]*a[i-1]  , f[i][j+1]+ p[m-j+i-1]*a[j+1] );
        }
    }
    ll maxn=-1;
    for(int i=1;i<=m;i++) maxn=std::max(maxn,f[i][i]+a[i]*p[m]);
    return maxn;
}

int main()
{
    for(int i=1;i<=90;i++) p[i]=p[i-1]<<1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        scanf("%d",a+j);
        ans+=dp();
    }
    printf("%lld\n",ans);
    return 0;
}
