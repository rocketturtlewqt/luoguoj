#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int mat[5050][5050];
int main(){
	int n,r;
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		int x,y,w;cin>>x>>y>>w;x+=1;y+=1;
		mat[x][y]+=w;
	}
	int maxx=0;
	for(int i=1;i<=5001;i++)
	for(int j=1;j<=5001;j++)
	mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
	for(int i=r;i<=5001;i++)
	for(int j=r;j<=5001;j++)
	maxx=max(maxx,mat[i][j]-mat[i-r][j]-mat[i][j-r]+mat[i-r][j-r]);
	printf("%d\n",maxx);
	return 0;
}
