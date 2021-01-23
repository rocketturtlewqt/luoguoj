#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
int n,a,q;char s[100];double dp[100][100];
int main(){
	cin>>n>>a>>q>>(s+1);
	if(n>50) return puts("1.000"),0;
	dp[0][0]=1;
	double p=a/100.0;
	int len=strlen(s+1);
	fp(i,1,n){
		int num=s[i]-'0';
		fp(j,0,i){
			if(num){
				dp[i][j]+=dp[i-1][j]*(1-p);
				if(j>0) dp[i][j]+=dp[i-1][j-1]*p;	
			}
			else{
				dp[i][j]+=dp[i-1][j]*p;
				if(j>0) dp[i][j]+=dp[i-1][j-1]*(1-p);
			}
		}
	}
	double ans=0;
	fp(i,q,n) ans+=dp[n][i];
	return printf("%.3lf\n",ans),0;
}
