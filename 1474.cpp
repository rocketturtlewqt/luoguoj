#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,v,value[100000],dp[100000];
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++) cin>>value[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
	for(int j=value[i];j<=v;j++)
	dp[j]+=dp[j-value[i]];
	cout<<dp[v]<<endl;
	return 0;
}
