#include<bits/stdc++.h>
using namespace std;
int n,m,up[120][120],le[120][120],ri[120][120],mat[120][120];
inline void start(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		cin>>mat[i][j];
	    if(mat[i][j]) up[i][j]=1,le[i][j]=j,ri[i][j]=j;
	}
}
inline void ycl(){
	for(int i=1;i<=n;i++)
	for(int j=2;j<=m;j++)
	if(mat[i][j-1]&&mat[i][j]) le[i][j]=le[i][j-1];
	for(int i=1;i<=n;i++)
	for(int j=n-1;j>=1;j--)
	if(mat[i][j+1]&&mat[i][j]) ri[i][j]=ri[i][j+1];
}
inline void solve(){
	int res=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(mat[i][j]&&mat[i-1][j]){
			up[i][j]+=up[i-1][j];
			ri[i][j]=min(ri[i][j],ri[i-1][j]);
			le[i][j]=max(le[i][j],le[i-1][j]);
			int a=ri[i][j]-le[i][j]+1;
			res=max(res,min(up[i][j],a));
		}
	}
	cout<<res<<endl;
}
int main(){
	start();
	ycl();
	solve();
	return 0;
}

