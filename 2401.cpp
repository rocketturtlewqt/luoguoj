#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=2015;
ll n,k,dp[1050][1050];
int main(){
	scanf("%lld%lld",&n,&k);
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
	for(int j=0;j<=k;j++){
		dp[i][j]=(dp[i][j]+(j+1)*dp[i-1][j])%mod;
		if(j) dp[i][j]=(dp[i][j]+(i-j)*dp[i-1][j-1])%mod;
	}
	printf("%lld\n",dp[n][k]%mod);
	return 0;
}
