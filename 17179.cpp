#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=-1e10;
ll n,m,dp[200],a[200][200],qz[200][200];
vector<ll> v[40000];
inline ll f(ll x){
	ll size=v[x].size(),maxx=inf;
	for(ll i=1;i<=n;i++) dp[i]=0;
	for(ll i=0;i<size;i++){
	    if(dp[i]+v[x][i]<v[x][i]) dp[i+1]=v[x][i];
	    else dp[i+1]=dp[i]+v[x][i];
	    maxx=max(maxx,dp[i+1]);
	}
	return maxx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		    qz[j][i]=qz[j-1][i]+a[j][i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			++m;
            for(ll k=1;k<=n;k++){
            	v[m].push_back(qz[j][k]-qz[i-1][k]);
			}
		}
	}
	ll maxx=inf;
	for(ll i=1;i<=m;i++) maxx=max(maxx,f(i));
	cout<<maxx<<endl;
	return 0;
}
