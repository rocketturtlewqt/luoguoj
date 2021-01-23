#include<bits/stdc++.h>
using namespace std;
int M,S,T,dp[400000];
int main(){
	cin>>M>>S>>T;
	for(int i=1;i<=T;i++){
		if(M>=10) dp[i]=dp[i-1]+60,M-=10;
		else dp[i]=dp[i-1],M+=4;
	}
	for(int i=1;i<=T;i++){
		dp[i]=max(dp[i],dp[i-1]+17);
		if(dp[i]>=S) return puts("Yes"),cout<<i<<endl,0;
	}
	return puts("No"),cout<<dp[T]<<endl,0;
}
