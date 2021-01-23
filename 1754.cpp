#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,dp[25][25];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) dp[i][j]=dp[i-1][j]+dp[i][j-1];
	return cout<<dp[n][n]<<endl,0;
}
