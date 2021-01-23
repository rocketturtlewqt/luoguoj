#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
int n,m,dp[101][101];
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline void start(){
	n=read(),m=read();
    fp(i,0,n) dp[i][0]=1;
}
inline void solve(){
	fp(i,1,n){
		int t;t=read();
		fp(j,0,t){
			fp(k,0,m-j){
				if(j==0&&k==0) continue;
				dp[i][j+k]+=dp[i-1][k];
				dp[i][j+k]%=1000007;
			}
		}
	}
	out(dp[n][m]%1000007),putchar('\n');
}
int main(){
	start();
	solve();
	return 0;
}
