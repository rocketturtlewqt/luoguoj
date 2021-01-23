#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,mat[600][600],a[600][600],b[600][600],dp[600][600];
int main(){
	while(scanf("%lld%lld",&n,&m)&&n&&m){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
	    for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++){
		    scanf("%lld",&mat[i][j]);
		    a[i][j]=a[i][j-1]+mat[i][j];
	    }
	    for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++){
	    	scanf("%lld",&mat[i][j]);
	    	b[i][j]=b[i-1][j]+mat[i][j];
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		dp[i][j]=max(dp[i][j-1]+b[i][j],dp[i-1][j]+a[i][j]);
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}
