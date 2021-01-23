#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
ll n,k;
inline ll get(ll x){
	ll sum=0;
	for(;x;x-=x&(-x)) sum++;
	return sum;
}
int main(){
	scf(n,k);
	ll ans=0;
	while(get(n)>k){
		ans+=n&(-n);
		n+=n&(-n);
	}
	cout<<ans<<endl;
	return 0;
}
