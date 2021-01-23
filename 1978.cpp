#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=4e6+5;
ll n,k,a[MAXN];
set<ll> s;
int main(){
	scf(n,k);fp(i,1,n) sc(a[i]);
	sort(a+1,a+n+1);
	fp(i,1,n){
		if(a[i]%k||s.find(a[i]/k)==s.end()){s.insert(a[i]);}
	}
	return cout<<s.size()<<endl,0;
}
