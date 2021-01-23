#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5;
int n,b,pos;
ll a[MAXN+1],l[(MAXN<<1)+1],r[(MAXN<<1)+1];
int main(){
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		ll x;cin>>x;
		if(x==b) pos=i;
		else a[i]=x>b?1:-1;
	}
	l[MAXN]=r[MAXN]=1;
	ll sum=0;
	for(int i=pos-1;i>=1;i--){
		sum+=a[i];l[sum+MAXN]++;
	}
	sum=0;
	for(int i=pos+1;i<=n;i++){
		sum+=a[i];r[sum+MAXN]++;
    }
    ll ans=0;
	for(int i=0;i<=(MAXN<<1);i++) if(l[i]&&r[(MAXN<<1)-i]) ans+=l[i]*r[(MAXN<<1)-i];
	cout<<ans<<endl;
	return 0; 
}
