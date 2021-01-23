#include<stdio.h>
#include<string.h>
#define maxn 51
int dp[maxn][maxn][maxn][maxn],d[maxn][maxn],n,m;
int max(int i,int j)
{
	return i>j?i:j;
}
void start()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
	scanf("%d",&d[i][j]);
}

void solve()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=1;k<=n;k++)
	for(int l=1;l<=m;l++)
	{
		int op1=max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1]);
		int op2=max(dp[i-1][j][k][l-1],dp[i][j-1][k-1][l]);
		dp[i][j][k][l]=max(op1,op2)+d[i][j];
		if(i!=k&&j!=l) dp[i][j][k][l]+=d[k][l];
	}
	printf("%d\n",dp[n][m][n][m]);
}
int main()
{
	start();
	solve();
	return 0;
}
