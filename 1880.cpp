#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[300],dp[300][300][2],qz[300];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
	for(int i=1;i<=2*n;i++) qz[i]=qz[i-1]+a[i];
	for(int i=1;i<=2*n;i++)
	for(int j=1;j<=2*n;j++){
	    if(i!=j) dp[i][j][0]=0x3f3f3f3f;
	    else dp[i][i][0]=0;
		dp[i][j][1]=0;
	}
	for(int len=2;len<=n;len++)
	for(int l=1;l<=2*n-len+1;l++){
		int r=l+len-1;
		for(int k=l;k<r;k++){
			dp[l][r][0]=min(dp[l][r][0],dp[l][k][0]+dp[k+1][r][0]);
			dp[l][r][1]=max(dp[l][r][1],dp[l][k][1]+dp[k+1][r][1]);
		}
		dp[l][r][0]+=qz[r]-qz[l-1];dp[l][r][1]+=qz[r]-qz[l-1];
	}
	ll minn=0x3f3f3f3f,maxx=-0x3f3f3f3f;
	for(int l=1;l<=2*n-n+1;l++){
		minn=min(minn,dp[l][l+n-1][0]);
		maxx=max(maxx,dp[l][l+n-1][1]);
	}
	cout<<minn<<endl;cout<<maxx<<endl;
	return 0;
}
