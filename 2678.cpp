#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll L,n,m,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>L>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	a[n+1]=L;
	ll l=-1,r=1e12,cnt=-1;
	while(l<=r){
		ll mid=(l+r)/2,
		   ans=0,
		   now=0;
		for(ll i=1;i<=n+1;i++){
			if(a[i]-a[now]<mid) ans++;
			else now=i;
		}
		if(ans<=m) l=mid+1,cnt=mid;
		else r=mid-1;
	}
	cout<<cnt<<endl;
	return 0;
}
