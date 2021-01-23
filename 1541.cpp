#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=552;
int n,m,a[MAXN],b[MAXN],book[50],dp[40][40][40][40];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++) cin>>b[j],book[b[j]]++;
	dp[0][0][0][0]=a[1];
	for(int j=0;j<=book[1];j++)
	for(int k=0;k<=book[2];k++)
	for(int u=0;u<=book[3];u++)
	for(int t=0;t<=book[4];t++){
		int num=j*1+k*2+u*3+t*4+1;
	    dp[j+1][k][u][t]=max(dp[j+1][k][u][t],dp[j][k][u][t]+a[num+1]);
		dp[j][k+1][u][t]=max(dp[j][k+1][u][t],dp[j][k][u][t]+a[num+2]);
		dp[j][k][u+1][t]=max(dp[j][k][u+1][t],dp[j][k][u][t]+a[num+3]);
		dp[j][k][u][t+1]=max(dp[j][k][u][t+1],dp[j][k][u][t]+a[num+4]);
	}
	printf("%d\n",dp[book[1]][book[2]][book[3]][book[4]]);
	return 0;
}
