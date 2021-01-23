#include<bits/stdc++.h>
using namespace std;
int n,a[200],dp[200];
int main(){
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    for(int j=0;j<i;j++){
    	if(j+1!=i) dp[i]=max(dp[i],dp[j]+abs(a[i]-a[j+1])*(i-j));
    	else dp[i]=max(dp[i],dp[j]+a[i]);
    }
    return cout<<dp[n]<<endl,0;
}
