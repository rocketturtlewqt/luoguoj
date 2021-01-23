#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500000;
ll a[MAXN];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++) printf("%lld ",a[i]);
	printf("%lld\n",a[n]);
	return 0;
}
