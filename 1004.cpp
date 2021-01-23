#include<stdio.h>
#include<string.h>
#define maxn 10
int dp[maxn][maxn][maxn][maxn],d[maxn][maxn],N;
int max(int i,int j)
{
	return i>j?i:j;
}
void start()
{
	int u,v,w;
	scanf("%d",&N);
	while(scanf("%d%d%d",&u,&v,&w)&&u&&v&&w)
	{
		d[u][v]=w;
	}
}

void solve()
{
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	for(int k=1;k<=N;k++)
	for(int l=1;l<=N;l++)
	{
		int op1=max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1]);
		int op2=max(dp[i-1][j][k][l-1],dp[i][j-1][k-1][l]);
		dp[i][j][k][l]=max(op1,op2)+d[i][j];
		if(i!=k&&j!=l) dp[i][j][k][l]+=d[k][l];
	}
	printf("%d\n",dp[N][N][N][N]);
}
int main()
{
	start();
	solve();
	return 0;
}
