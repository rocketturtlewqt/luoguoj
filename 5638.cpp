#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,k,a[N];
queue<ll> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	ll sum=0,ans=0,maxx=0;
	if(k>=n-1) return cout<<0<<endl,0;
	for(ll i=1;i<n;i++) cin>>a[i],sum+=a[i];
	for(ll i=1;i<n;i++){
		q.push(a[i]);ans+=a[i];
		ll size=q.size();
		if(size>k) ans-=q.front(),q.pop();
		maxx=max(maxx,ans);
	}
	cout<<sum-maxx<<endl;
	return 0;
}
