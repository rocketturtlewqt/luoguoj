#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=10007;
const ll N=1e5+5;
ll n,m,num[N],col[N],jqz[2][N],qz[2][N],posqz[2][N],sum;
vector<vector<vector<ll>> >vec;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>num[i];
	for(ll i=1;i<=n;i++) cin>>col[i];
	for(ll i=1;i<=n;i++){
		ll len=vec[i%2][col[i]].size();
	    if(len!=0){
            sum=(sum+i*num[i]);
            sum=(sum+jqz[i%2][col[i]])%mod;
            sum=(sum+i*qz[i%2][col[i]])%mod;
            sum=(sum+num[i]*posqz[i%2][col[i]])%mod;
        }
        vec[i%2][col[i]].push_back(num[i]);
        jqz[i%2][col[i]]=(jqz[i%2][col[i]]+i*num[i])%mod;
        qz[i%2][col[i]]=(qz[i%2][col[i]]+num[i])%mod;
        posqz[i%2][col[i]]=(posqz[i%2][col[i]]+i)%mod;
	}
	return 0;
}
