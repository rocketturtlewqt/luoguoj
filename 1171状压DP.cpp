#include<stdio.h>
#include<string.h>
#define maxium 20
#define inf 99999999;
int dp[1<<maxium][maxium];
int d[maxium][maxium];
int n;
//S为已访问过的节点的集合,v为当前结点 
int min (int a,int b)
{
	return a>b?b:a;
}
int rec(int S,int v)
{
	int u;
	if(dp[S][v]>=0)	return dp[S][v];
	if(S==(1<<n)-1&&v==0) return dp[S][v]=0;
	int res=inf;
	for(u=0;u<n;u++)
	if(!(S>>u&1))
	res=min(res,rec(S|(1<<u),u)+d[v][u]);
	return dp[S][v]=res;
}
void solve ()
{
	memset(dp,-1,sizeof(dp));
	printf("%d\n",rec(0,0));
}
int main ()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&d[i][j]);
	solve();
	return 0;
}
