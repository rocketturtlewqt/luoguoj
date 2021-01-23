#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],dp[1000000];
int main(){
	int maxx=-0x3f3f3f3f;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dp[i]=max(dp[i-1]+a[i],a[i]),maxx=max(maxx,dp[i]);
 	cout<<maxx<<endl;
	return 0;
}
