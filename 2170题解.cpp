#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int f[100000],p[100000],i,j,x,y,k,m,n,s[100000],dp[100000],tot;
int find(int u)
{
    if(f[u]==u) return u;
    else return f[u]=find(f[u]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        f[i]=i,p[i]=1; //p预处理为1,因为一开始每个集合只有一个数
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        int u=find(x);int v=find(y); //并查集
        if(u!=v) f[u]=v,p[v]+=p[u];  //p记录集合元素个数
    }
    for(i=1;i<=n;i++) //找到每个集合的根节点，把集合的元素个数存起来
    if(f[i]==i)
    {
        tot++;
        s[tot]=p[i];
    }
    for(i=1;i<=tot;i++)
    printf("%d ",s[i]);
    for(i=1;i<=tot;i++) //背包问题
        for(j=2*m;j>=s[i];j--)
            dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
    int ans=999999999,minn=999999999;
    for(i=1;i<=2*m;i++) //找到最接近m的
    {
        if(minn>abs(dp[i]-m)) minn=abs(dp[i]-m),ans=dp[i];
    }
//    if(ans==999999999) printf("0");
//    else    printf("%d",ans);
    return 0;
}
