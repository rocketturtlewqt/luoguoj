#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans,sum;
int main(){
	cin>>n>>k;
	ans=n*k;
	ll l,r;
	for(l=1;l<=n;l=r+1){
		int t=k/l;
		if(t!=0) r=min(k/t,n);
		else r=n;
		sum+=(k/l)*(l+r)*(r-l+1)/2;
	}
	cout<<ans-sum<<endl;
	return 0;
}
