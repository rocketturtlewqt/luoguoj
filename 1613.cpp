#include<stdio.h>
#include<string.h>
#define maxn 101
long int dp[maxn][maxn][65];
int d[maxn][maxn];
int n,m;
int min (int i,int j)
{
	return i>j?j:i;
}
void start()
{
	int u,v;
	memset(d,0x3f3f3f3f,sizeof(d));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d",&u,&v);
	    d[u][v]=1;
	    dp[u][v][0]=1;
	}
}
void set()
{
	for(int l=1;l<=64;l++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	{
		if(dp[i][k][l-1]&&dp[k][j][l-1])
		{
			dp[i][j][l]=1;
			d[i][j]=1;
		}
	}
}
void Floyd()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
}
int main()
{
	start();
	set();
	Floyd();
	printf("%d\n",d[1][n]);
	return 0;
}
