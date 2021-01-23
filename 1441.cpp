#include<bits/stdc++.h>
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
using namespace std;
int n,m,ans,maxx,a[25],flag[25],dp[5050];
inline void solve(){
	int ans=0,tot=0;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	fp(i,1,n){
		if(flag[i]) continue;
		fb(j,tot,0) if(dp[j]&&!dp[j+a[i]]) ans++,dp[j+a[i]]=1;
		tot+=a[i];
	}
	maxx=max(maxx,ans);
}
inline void dfs(int pos,int now){
	if(now>m) return;
	if(pos==n+1){
	    if(now==m) solve();
	    return;
	}
	dfs(pos+1,now);
	flag[pos]=1;
	dfs(pos+1,now+1);
	flag[pos]=0;
}
int main(){
	scf(n,m);
	fp(i,1,n) sc(a[i]);
	dfs(1,0);
	return cout<<maxx<<endl,0;
}
