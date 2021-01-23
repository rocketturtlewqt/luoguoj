#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=3e6+5;
ll n,p,x,y;
inline int exgcd(ll a,ll b,ll &x,ll &y){
     if(!b){x=1,y=0;return a;}
     int d=exgcd(b,a%b,x,y);
     int z=x;x=y;y=z-a/b*y;
     return d;
}
int main(){
	scf(n,p);
	fp(i,1,n){
		exgcd(i,p,x,y);
		printf("%lld\n",(x%p+p)%p);
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e7;
ll n,p,inv[MAXN],f[MAXN],c[MAXN];
ll quick_pow(ll x,ll q){
	ll ans=1;
	while(q){
		if(q&1) ans=ans*x%p;
		x=x*x%p;q>>=1;
	}
	return ans%p;
}
int main(){
    scanf("%lld%lld",&n,&p);
    c[0]=1;
    for(int i=1;i<=n;i++){
    	c[i]=i*c[i-1]%p;
	}
	f[n]=quick_pow(c[n],p-2);
	for(int i=n-1;i>=1;i--) f[i]=(f[i+1]*(i+1))%p,inv[i]=(f[i]*c[i-1])%p;
	inv[n]=(f[n]*(c[n-1]))%p;
	for(int i=1;i<=n;i++) printf("%lld\n",inv[i]);
	return 0;
}
*/
