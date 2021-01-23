#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000],dp[5000],o[5000],t[5000];
int main(){
	cin>>n>>m;memset(dp,0x3f3f3f,sizeof(dp));dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) o[i]=o[i-1]+1,t[i]=t[i-1];
		else o[i]=o[i-1],t[i]=t[i-1]+1;
	}
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)
	if(abs(o[i]-o[j]-t[i]+t[j])<=m||o[i]-o[j]==0||t[i]-t[j]==0) dp[i]=min(dp[i],dp[j]+1);
	cout<<dp[n]<<endl;
	return 0;
}
