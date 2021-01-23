#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll mod=1e9+7;
inline ll quick_pow(ll x,ll p){
	ll res=1;
	while(p){
		if(p&1) res=res*x%mod;
		x=x*x%mod;p>>=1;
	}
	return res;
}
inline ll cmod(ll n,ll m){
	ll a=1,b=1;
	fp(i,2,n) a=a*i%mod;
	fp(i,2,m) b=b*i%mod;
	fp(i,2,n-m) b=b*i%mod;
	return a*quick_pow(b,mod-2)%mod;
}
int main(){
	int x;
	sc(x);
	printf("%lld\n",cmod(2*x,x)*quick_pow(x+1,mod-2)%mod);
	return 0;
}
