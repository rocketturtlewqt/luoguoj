#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,t;
}node[150];
int n,m,r,dp_num[150][150],dp_time[150][150];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>node[i].x>>node[i].y>>node[i].t;
	cin>>m>>r;
	for(int i=1;i<=n;i++)
	for(int j=m;j>=node[i].x;j--)
	for(int k=r;k>=node[i].y;k--){
		if(dp_num[j][k]<dp_num[j-node[i].x][k-node[i].y]+1){
			dp_time[j][k]=dp_time[j-node[i].x][k-node[i].y]+node[i].t;
			dp_num[j][k]=dp_num[j-node[i].x][k-node[i].y]+1;
		}
		else{
			if(dp_num[j][k]==dp_num[j-node[i].x][k-node[i].y]+1)
	        dp_time[j][k]=min(dp_time[j][k],dp_time[j-node[i].x][k-node[i].y]+node[i].t);
		}
	}
	cout<<dp_time[m][r]<<endl;
	return 0;
}
