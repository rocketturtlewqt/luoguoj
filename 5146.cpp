#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
ll n,a[MAXN];
int main(){
	ll maxx=-0x3f3f3f3f,minn=0x3f3f3f3f;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];minn=a[1];
	for(int i=2;i<=n;i++){
		maxx=max(a[i]-minn,maxx);
		minn=min(minn,a[i]);
	}
	cout<<maxx<<endl;
	return 0;
}
