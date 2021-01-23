#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,K,dp[115][15],f[115][115][15],sum[115],s1[115],s2[115];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	if(m==1){
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			sum[i]=sum[i-1]+x;
		}
		for(int k=1;k<=K;k++)
		for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
		dp[i][k]=max(dp[i][k],max(dp[i-1][k],dp[j][k-1]+sum[i]-sum[j]));
		printf("%d\n",dp[n][K]);
	}
	else{
		for(int i=1;i<=n;i++){
			int x,y;scanf("%d%d",&x,&y);
			s1[i]=s1[i-1]+x;
			s2[i]=s2[i-1]+y;
		}
		for(int t=1;t<=K;t++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			f[i][j][t]=max(f[i-1][j][t],f[i][j-1][t]);
        	for(int l=0;l<i;l++) 
			f[i][j][t]=max(f[i][j][t],max(f[l][j][t],f[l][j][t-1]+s1[i]-s1[l]));
			for(int l=0;l<j;l++)
			f[i][j][t]=max(f[i][j][t],max(f[i][l][t],f[i][l][t-1]+s2[j]-s2[l]));
			if(i==j){
				for(int l=0;l<i;l++)
				f[i][j][t]=max(f[i][j][t],max(f[l][l][t],f[l][l][t-1]+s1[i]-s1[l]+s2[j]-s2[l]));
			}
		}
		printf("%d\n",f[n][n][K]);
	}
	return 0;
} 
