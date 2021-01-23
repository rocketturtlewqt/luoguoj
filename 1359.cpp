#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
int n,dp[500];
int main(){
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[1]=0;
	sc(n);
	fp(i,1,n-1){
		fp(j,i+1,n){
			int xx;sc(xx);
			dp[j]=min(dp[j],dp[i]+xx);
		}
	}
	return printf("%d\n",dp[n]),0;
}
