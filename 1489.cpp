#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,blood[201],dp[8001][201];
int main(){
	ll sum=0,minn=0x3f3f3f3f,min_a,min_b;cin>>n;dp[0][0]=1;
	for(int i=1;i<=n;i++) cin>>blood[i],sum+=blood[i];
	for(int i=1;i<=n;i++)
	for(int j=sum/2;j>=blood[i];j--)
	for(int k=n/2;k>=1;k--)
	if(dp[j-blood[i]][k-1]) dp[j][k]=1;
    for(int i=0;i<=sum/2;i++){
    	if(dp[i][n/2]&&minn>abs(sum-2*i)){
    		minn=sum-2*i;
    		min_a=i,min_b=sum-i;
		}
	}
	return cout<<min_a<<' '<<min_b<<endl,0;
}
