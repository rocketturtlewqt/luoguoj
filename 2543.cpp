#include<bits/stdc++.h>
using namespace std;
int a,b;
char s1[20000],s2[20000];
inline void start(){
	cin>>s1>>s2;
	a=strlen(s1),b=strlen(s2);
}
int dp[10001][10001];
int main(){
	start();
	for(int i=0;i<=a;i++)
	for(int j=0;j<=b;j++){
		if(s1[i]==s2[j]) dp[i+1][j+1]=dp[i][j]+1;
		else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
	}
	printf("%d\n",dp[a][b]);
	return 0;
}
