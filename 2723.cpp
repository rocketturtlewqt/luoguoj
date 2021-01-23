#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=4e6+5;
ll k,n,a[MAXN],f[MAXN],s[MAXN];
int main(){
	scf(k,n);
	fp(i,1,k) sc(a[i]);
	f[0]=1;
	fp(i,1,n){
		ll minn=999999999999;
		fp(j,1,k){
			while(a[j]*f[s[j]]<=f[i-1]) s[j]++;
			minn=min(minn,a[j]*f[s[j]]); 
		} 
		f[i]=minn;
	}
	printf("%lld",f[n]);
	return 0;
}
