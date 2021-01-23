#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200;
ll p,q,a[MAXN],sum[MAXN],dp[1020][1020];
int main(){
	scanf("%lld%lld",&p,&q);
	for(int i=1;i<=q;i++) scanf("%lld",&a[i]);
	a[0]=0;a[++q]=p+1;
	for(int i=1;i<=q;i++) sum[i]=sum[i-1]+a[i]-a[i-1]-1;
	for(int k=2;k<=q;k++)
	for(int i=1;i<=q-k+1;i++){
		int j=i+k-1;
		for(int t=i;t<j;t++){
			if(!dp[i][j]) dp[i][j]=dp[i][t]+dp[t+1][j]+sum[j]-sum[i-1]+j-i-1;
			else dp[i][j]=min(dp[i][j],dp[i][t]+dp[t+1][j]+sum[j]-sum[i-1]+j-i-1);
		}
	}
	printf("%lld\n",dp[1][q]);
	return 0;
}
