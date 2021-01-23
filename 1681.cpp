#include<bits/stdc++.h>
using namespace std;
int n,m,up[3000][3000],le[3000][3000],ri[3000][3000],mat[3000][3000],dp[3000][3000];
inline void start(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		cin>>mat[i][j];
		up[i][j]=1;
		le[i][j]=ri[i][j]=j;
	}
}
inline void ycl(){
	for(int i=1;i<=n;i++)
	for(int j=2;j<=m;j++)
	if(mat[i][j]!=mat[i][j-1]) le[i][j]=le[i][j-1];
	for(int i=1;i<=n;i++)
	for(int j=m-1;j>=1;j--)
	if(mat[i][j]!=mat[i][j+1]) ri[i][j]=ri[i][j+1];
}
inline void solve(){
	start();ycl();int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(mat[i][j]!=mat[i-1][j]){
		up[i][j]+=up[i-1][j];
		le[i][j]=max(le[i][j],le[i-1][j]);
		ri[i][j]=min(ri[i][j],ri[i-1][j]);
		int a=ri[i][j]-le[i][j]+1;
		maxx=max(maxx,min(a,up[i][j]));
	}
	cout<<maxx<<endl;
}
int main(){
    solve();
    return 0;
}
/*
4 4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/
