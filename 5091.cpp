#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
ll a,m,b;
inline ll quick_pow(ll x,ll p){
	ll res=1;
	while(p){
		if(p&1) res=res*x%m;
		x=x*x%m;p>>=1;
	}
	return res;
}
inline ll phi(ll n){
	ll ans=n,q=sqrt(n);
	fp(i,2,q){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
int main(){
	char c;ll flag=0;
	scf(a,m);
	ll euler=phi(m);
	while(!isdigit(c=getchar()));
	while(isdigit(c)){
		b=b*10+c-'0';
		if(b>=euler){
			flag=1;
			b%=euler;
		}
		c=getchar();
	}
	if(flag) b+=euler;
	printf("%lld\n",quick_pow(a,b));
	return 0;
}
