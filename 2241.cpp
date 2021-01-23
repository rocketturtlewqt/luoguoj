#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
	ll ans=0,cnt=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			ans+=min(i,j);
			cnt+=i*j;
		}
	}
	cout<<ans<<" "<<cnt-ans<<endl;
	return 0;
}
