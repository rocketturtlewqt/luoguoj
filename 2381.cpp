#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=4e6+5;
ll n,sum,maxx,a[MAXN],qz[MAXN];
int main(){
	sc(n);
	fp(i,1,n) sc(a[i]),sum+=a[i];
	fp(i,n+1,2*n) a[i]=a[i-n];
	fp(i,1,2*n) qz[i]=qz[i-1]+a[i];
	ll mid=sum/2,pos; 
	fp(i,0,2*n){
		if(qz[i]+mid>qz[2*n]) break;
		pos=lower_bound(qz+1,qz+2*n+1,qz[i]+mid)-qz;
		maxx=max(maxx,min(qz[pos]-qz[i],sum-(qz[pos]-qz[i])));
	}
	printf("%lld",maxx);
	return 0;
}
/*
5
1
2
3
4
5
*/
