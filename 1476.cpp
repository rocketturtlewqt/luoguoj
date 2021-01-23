#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
int n,m,dp[110][110];
int main(){
	scf(n,m);
	fp(i,1,m){
		int x,y,z;scff(x,y,z);
		dp[x][y]=z;
	}
	fp(k,1,n+1){
		fp(i,1,n+1){
			fp(j,1,n+1){
				if(i!=j&&j!=k&&dp[i][k]&&dp[k][j])
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	printf("%d\n",dp[1][n+1]);
	fp(i,1,n+1){
		if(dp[1][i]+dp[i][n+1]==dp[1][n+1]) printf("%d ",i);
	}
	puts("");
	return 0;
}
