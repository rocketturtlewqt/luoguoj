#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int V,M,N,dp[500][500];
struct Node{
	int v,m,ca;
}node[100];
int main(){
	cin>>V>>M;cin>>N;
	for(int i=1;i<=N;i++) cin>>node[i].v>>node[i].m>>node[i].ca;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;i++)
	for(int j=V;j>=node[i].v;j--)
	for(int k=M;k>=node[i].m;k--)
	dp[j][k]=max(dp[j][k],dp[j-node[i].v][k-node[i].m]+node[i].ca);
	cout<<dp[V][M]<<endl; 
	return 0;
}
