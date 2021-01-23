#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h[7000],par[7000],dp[7000][2];
vector<ll> son[7000];
inline void f(ll x){
	dp[x][0]=0;dp[x][1]=h[x];
	for(int i=0;i<son[x].size();i++){
        ll so=son[x][i];
        f(so);
        dp[x][0]+=max(dp[so][0],dp[so][1]);
        dp[x][1]+=dp[so][0];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	ll s,p,root;
	for(int i=1;i<=n;i++) par[i]=i;
	while(cin>>s>>p&&s&&p){son[p].push_back(s);par[s]=p;}
	for(int i=1;i<=n;i++) if(par[i]==i) root=i;
	f(root);
	cout<<max(dp[root][0],dp[root][1])<<endl;
	return 0;
}
