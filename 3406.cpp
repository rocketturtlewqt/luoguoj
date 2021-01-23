#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,m,p[N],a[N],b[N],c[N],t[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>p[i];
	for(ll i=1;i<n;i++) cin>>a[i]>>b[i]>>c[i];
	for(ll i=1;i<m;i++){
		ll u=p[i],v=p[i+1];
		if(u>v) swap(u,v);
		t[u]++;t[v]--;
	} 
	for(ll i=1;i<n;i++) t[i]+=t[i-1];
	ll sum=0;
	for(ll i=1;i<n;i++) sum+=min(a[i]*t[i],b[i]*t[i]+c[i]);
	cout<<sum<<endl;
	return 0;
}
