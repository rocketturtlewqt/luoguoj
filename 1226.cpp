#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(ll a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline ll quickpow(ll a,ll b,ll k){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%k;
		a=a*a%k;
	}
	return ans;
}
inline void solve(){
	ll a,b,k;a=read(),b=read(),k=read();
	printf("%lld^%lld mod %lld=%lld\n",a,b,k,quickpow(a,b,k));
}
int main(){
	solve();
	return 0;
}
