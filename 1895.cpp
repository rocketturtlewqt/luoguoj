#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=1e6+5;
ll T,n,len[MAXN];
inline void init(){
	for(int i=1;i<10;i++) len[i]=len[i-1]+1;
	for(int i=10;i<100;i++) len[i]=len[i-1]+2;
	for(int i=100;i<1000;i++) len[i]=len[i-1]+3;
	for(int i=1000;i<10000;i++) len[i]=len[i-1]+4;
	for(int i=10000;i<100000;i++) len[i]=len[i-1]+5;
}
int main(){
	sc(T);
	init();
	while(T--){
		sc(n);
		ll ans=0,pos=0;
		while(ans+len[pos]<n){
			ans+=len[pos];
			pos++;
		}
		n-=ans;
		ll k2=0;
		while(++k2){
			if(len[k2]>=n) break;
		}
		printf("%lld\n",(ll)(k2/pow(10,len[k2]-n))%10);
	}
	return 0;
}
