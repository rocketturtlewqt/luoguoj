    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    const int maxn=51;
    const int INF=2147483647;
    int n,k,f[maxn],b[maxn],ans,dp[maxn*100];
void dfs(int x)
{
	if(x==k+1)
	{
//		for(int i=1;i<=k;i++)
//       	printf("%d ",w[i]);
//       	printf("\n");
//		memset(dp,0x3f3f3f3f,sizeof(dp));
        memset(dp,0,sizeof(dp));
        int i=0;
//		dp[0]=0;
//		for(int i=1;i<=k;i++)
		for(i;dp[i]<=n;)
		{
			i++;
			dp[i]=0x3f3f3f3f;
		    for(int j=1;j<=k&&i-f[j]>=0;j++)
            dp[i]=min(dp[i],dp[i-f[j]]+1);
        }
		if(ans<i-1)
        {
            for(int j=1;j<=k;j++)
            {
                b[j]=f[j];
                ans=i-1;
            }
		}
		return;
	}
	for(int i=f[x-1]+1;i<=f[x-1]*n+1;i++)
	{
		f[x]=i;
		dfs(x+1);
	}
}
    int main() 
    {
        scanf("%d%d",&n,&k);
        f[1]=1;
        dfs(2);
        for(int i=1;i<=k;i++)printf("%d ",b[i]);
        printf("\n");
        printf("MAX=%d\n",ans);
        return 0;
}
