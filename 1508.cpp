#include<bits/stdc++.h>
using namespace std;
int n,m,dp[250][250],mat[250][250],book[250][250];
int main(){
	int maxx=-0x3f3f3f3f;cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mat[i][j];
	dp[n][m/2+1]=mat[n][m/2+1];book[n][m/2+1]=1;
	dp[n][m/2]=mat[n][m/2];book[n][m/2]=1;
	dp[n][m/2+2]=mat[n][m/2+2];book[n][m/2+2]=1;
    for(int i=n;i>=1;i--)
    for(int j=1;j<=m;j++){
    	if(book[i][j]&&i-1>=1){
    		dp[i-1][j]=max(dp[i-1][j],dp[i][j]+mat[i-1][j]);book[i-1][j]=1;
    		if(j-1>=1) dp[i-1][j-1]=max(dp[i-1][j-1],dp[i][j]+mat[i-1][j-1]),book[i-1][j-1]=1;
    		if(j+1<=m) dp[i-1][j+1]=max(dp[i-1][j+1],dp[i][j]+mat[i-1][j+1]),book[i-1][j+1]=1;
		}
	}
	for(int i=1;i<=m;i++) maxx=max(maxx,dp[1][i]);
	cout<<maxx<<endl;
	return 0;
}
