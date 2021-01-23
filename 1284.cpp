#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=900;
ll n,a[50],maxx,sum,book[MAXN][MAXN];
inline ll judge(ll x,ll y,ll z){
	if(x+y>z||x+z>y||y+z>x) return 1;
	return 0;
}
inline double f(double a,double b,double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	book[0][0]=1;
	for(ll i=1;i<=n;i++)
	for(ll j=sum/2;j>=0;j--)
	for(ll k=sum/2;k>=0;k--){
		if(j-a[i]>=0) book[j][k]=max(book[j-a[i]][k],book[j][k]);
	    if(k-a[i]>=0) book[j][k]=max(book[j][k-a[i]],book[j][k]);
	}
    for(ll j=0;j<=sum/2;j++)
    for(ll k=0;k<=sum/2;k++){
    	if(!book[j][k]) continue;
    	if(!judge(j,k,sum-j-k)) book[j][k]=0;
    	if(book[j][k]) maxx=max(maxx,(ll)(100*f(double(j),double(k),double(sum-j-k)))); 
	}
	if(maxx) printf("%lld\n",maxx);
	else puts("-1");
	return 0;
}
