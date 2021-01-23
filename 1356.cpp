#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
ll T,n,k;
inline int p(int xx){
	xx%=k;
	if(xx<0) xx+=k;
	return xx;
}
int main(){
	sc(T);
	while(T--){
		int x;scf(n,k);
		vector<vector<int> > dp(n+100,vector<int>(k+100,0));
		sc(x);
		dp[1][p(x)]=dp[1][(p(-x))]=1;
		fp(i,2,n){
			sc(x);
			fp(j,0,k-1){
				dp[i][j]=max(dp[i-1][p(j-x)],dp[i-1][p(j+x)]);
			}
		}
		if(dp[n][0]) puts("Divisible");
		else puts("Not divisible");
	}
	return 0;
}
