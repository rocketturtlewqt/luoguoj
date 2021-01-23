#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=4e6+5;
const ll mod=1e9+7;
ll n,a[MAXN],b[MAXN],c[MAXN];
int main(){
	sc(n);fp(i,1,n) sc(a[i]),b[i]=c[i]=a[i];
	fb(i,n,1){
		c[i]=(c[i]+c[i+1])%mod;
		b[i]=(b[i]*c[i+1]+b[i+1])%mod;
		a[i]=(a[i]*b[i+1]+a[i+1])%mod;
	}
	printf("%lld\n",(6*a[1]%mod+mod)%mod);
	return 0;
}
