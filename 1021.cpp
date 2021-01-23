#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k,maxx;
int w[51],end[51],dp[10000];
void start()
{
	cin>>n>>k;
	w[1]=1;
}
void dfs(int x)
{
	if(x==k+1)
	{
        memset(dp,0,sizeof(dp));
        int i=0;
		for(i;dp[i]<=n;)
		{
			i++;
			dp[i]=0x3f3f3f3f;
		    for(int j=1;j<=k&&i-w[j]>=0;j++)
            dp[i]=min(dp[i],dp[i-w[j]]+1);
        }
		if(maxx<i-1)
        {
        	maxx=i-1;
            for(int j=1;j<=k;j++)
            end[j]=w[j];
		}
		return;
	}
	for(int i=w[x-1]+1;i<=n*w[x-1]+1;i++)
	{
		w[x]=i;
		dfs(x+1);
	}
}
int main()
{
	start();
	dfs(2);
	for(int i=1;i<=k;i++)
	printf("%d ",end[i]);
	printf("\nMAX=%d\n",maxx);
	return 0;
}
