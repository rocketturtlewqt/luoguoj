#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
int n,s,t,dp[200][200];
inline void floyd(){
	fp(k,1,n){
		fp(i,1,n){
			fp(j,1,n){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main(){
	scff(n,s,t);
	fp(i,1,n){
		fp(j,1,n){
			if(i==j) dp[i][j]=0;
			else dp[i][j]=0x3f3f3f3f;
		}
	}
	fp(i,1,n){
		int num,x;
		sc(num);
		fp(j,1,num){
			sc(x);
			if(j==1) dp[i][x]=0;
			else dp[i][x]=1;
		}
	}
	floyd();
	if(dp[s][t]!=0x3f3f3f3f) printf("%d\n",dp[s][t]);
	else puts("-1");
	return 0; 
}
