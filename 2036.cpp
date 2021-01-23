#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s[15],b[15],vis[15],minn;
inline ll dfs(ll ss,ll bb,ll num){
	if(num) minn=min(minn,abs(ss-bb));
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(ss*s[i],bb+b[i],num+1);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	minn=1e15;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>s[i]>>b[i];
	dfs(1,0,0);
	cout<<minn<<endl;
	return 0;
}
