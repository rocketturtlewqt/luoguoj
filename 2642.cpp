#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
ll n,a[MAXN],m1[MAXN],dp1[MAXN],m2[MAXN],dp2[MAXN];
int main(){
	ll maxx=-0x3f3f3f3;cin>>n;
	for(int i=0;i<=n+1;i++) dp1[i]=dp2[i]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		m1[i]=max(m1[i-1],(ll)0)+a[i];
		dp1[i]=max(dp1[i-1],m1[i]);
	}
	for(int i=n;i>=1;i--){
		m2[i]=max(m2[i+1],(ll)0)+a[i];
		dp2[i]=max(dp2[i+1],m2[i]);
	} 
	for(int i=2;i<n;i++) maxx=max(maxx,dp1[i-1]+dp2[i+1]);
	cout<<maxx<<endl;
	return 0;
}
