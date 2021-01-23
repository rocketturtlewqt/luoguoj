#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5;
int n,b,pos;
ll a[MAXN+1];
map<int,int> l;
map<int,int> r;
int main(){
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		ll x;cin>>x;
		if(x==b) pos=i;
		else a[i]=x>b?1:-1;
	}
	l[0]=r[0]=1;
	ll sum=0;
	for(int i=pos-1;i>=1;i--){
		sum+=a[i];l[sum]++;
	}
	sum=0;
	for(int i=pos+1;i<=n;i++){
		sum+=a[i];r[sum]++;
    }
    ll ans=0;
	for(int i=-MAXN;i<=MAXN;i++) if(l[i]&&r[-i]) ans+=l[i]*r[-i];
	cout<<ans<<endl;
	return 0; 
}
