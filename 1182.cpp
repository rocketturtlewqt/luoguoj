#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,m,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ll l=-1,r=1e12,cnt=-1;
	for(ll i=1;i<=n;i++) cin>>a[i],l=max(l,a[i]);
	while(l<=r){
		ll mid=(l+r)/2,
		   ans=0,sum=0;
		for(ll i=1;i<=n;i++){
            if(sum+a[i]>mid){
                sum=a[i];
                ans++;
            }else{
                sum+=a[i];
            }
        }
		if(ans+1<=m) r=mid-1,cnt=mid;
		else l=mid+1;
	}
	cout<<cnt<<endl;
	return 0;
}
