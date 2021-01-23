#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,t[2000][2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c>>d;
		for(int j=a;j<=c;j++) t[j][b]+=1,t[j][d+1]-=1;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t[i][j]+=t[i][j-1];
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
