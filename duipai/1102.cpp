#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long ll;
#define maxium 1000000
int n;
ll a[maxium],c;
inline void solve(){
	sort(a+1,a+n+1);
	ll sum=0;
	for(int i=1;i<=n;i++){
		ll num=a[i]+c;
		sum+=upper_bound(a+1,a+n+1,num)-lower_bound(a+1,a+n+1,num);
	} 
	printf("%lld\n",sum);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	solve();
	return 0;
}
