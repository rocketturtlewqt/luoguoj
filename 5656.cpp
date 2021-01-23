#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
ll T;
inline ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){x=1;y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-a/b*y;
	return d;
}
int main(){
	sc(T);
	while(T--){
	    ll x,y,a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		ll gcd=__gcd(a,b);
		if(c%gcd){
			puts("-1");
			continue;
		}
		exgcd(a,b,x,y);
		x*=(c/gcd);y*=(c/gcd);
		ll k1=floor(-x*gcd*1.0/b),k2=ceil(y*gcd*1.0/a);
//		prllf("%d %d %d %d\n",x,y,k1,k2);
		if(k2-k1<=1) printf("%lld %lld\n",x+(k1+1)*(b/gcd),y-(k2-1)*(a/gcd));
		else{
			printf("%lld %lld %lld %lld %lld\n",k2-k1-1,x+(k1+1)*(b/gcd),y-(k2-1)*(a/gcd),x+(k2-1)*(b/gcd),y-(k1+1)*(a/gcd));
		}
	}
	return 0;
}
