#include<bits/stdc++.h>
using namespace std;
int v,n,c,dp[12000],vi[12000],w[12000];
int main(){
	int maxx=-0x3f3f3f3f;cin>>v>>n>>c;for(int i=1;i<=n;i++) cin>>vi[i]>>w[i];
	for(int i=1;i<=n;i++)
	for(int j=c;j>=w[i];j--)
	dp[j]=max(dp[j],dp[j-w[i]]+vi[i]);
	int flag=0;
	for(int i=1;i<=c;i++) if(dp[i]>=v) maxx=max(maxx,c-i),flag=1;
	if(flag) cout<<maxx<<endl;
	else puts("Impossible");
	return 0; 
}
