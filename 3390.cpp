#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll mod=1e9+7;
ll n,k,mat[120][120],res[120][120];
inline void mul(ll f[120][120],ll a[120][120]){
	ll c[120][120];memset(c,0,sizeof(c));
	fp(i,1,n) fp(j,1,n) fp(k,1,n) c[i][j]=(c[i][j]+f[i][k]*a[k][j])%mod;
	memcpy(f,c,sizeof(c));
}
inline void mulself(ll a[120][120]){
	ll c[120][120];memset(c,0,sizeof(c));
	fp(i,1,n) fp(j,1,n) fp(k,1,n) c[i][j]=(c[i][j]+a[i][k]*a[k][j])%mod;
	memcpy(a,c,sizeof(c));
}
int main(){
	scf(n,k);
	fp(i,1,n) fp(j,1,n) sc(mat[i][j]);
	fp(i,1,n) fp(j,1,n) if(i==j) res[i][j]=1;
	ll p=k;
	while(p){
		if(p&1) mul(res,mat);
		mulself(mat);p>>=1;
	}
	fp(i,1,n){
		fp(j,1,n) printf("%lld ",res[i][j]%mod);
		puts("");
	}
	return 0;
}
