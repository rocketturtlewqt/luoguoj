#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=10007;
inline ll quick_pow(ll x,ll p){
 	ll res=1;
 	while(p){
 		if(p&1) res=(res*x)%mod;
 		x=(x*x)%mod, p>>=1;
 	}
 	return res;
 }
inline ll C_mod(ll n,ll m){
 	ll a=1,b=1;
 	for(int i=2;i<=n;++i)
 		a=(a*i)%mod;
 	for(int i=2;i<=m;++i)
 		b=(b*i)%mod;
 	for(int i=2;i<=n-m;++i)
 		b=(b*i)%mod;
 	return (a*quick_pow(b,mod-2))%mod;
}
int a,b,k,n,m;
int main(){
	cin>>a>>b>>k>>n>>m;
	cout<<(quick_pow(a,n)*quick_pow(b,k-n)*C_mod(k,n))%mod<<endl;
}
