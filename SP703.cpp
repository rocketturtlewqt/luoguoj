#include<bits/stdc++.h>
using namespace std;
int T,L,n,pos[1250],cost[215][215],dp[1250][215][215];
int main(){
    cin>>T;
    while(T--){
        cin>>L>>n;int minn=0x3f3f3f3f;memset(dp,0x3f3f3f3f,sizeof(dp));
		for(int i=1;i<=L;i++) for(int j=1;j<=L;j++) cin>>cost[i][j];
		for(int i=1;i<=n;i++) cin>>pos[i];
		dp[0][1][2]=0;pos[0]=3;
		for(int i=0;i<n;i++)
		for(int j=1;j<=L;j++)
		for(int k=1;k<=L;k++){
			int z=pos[i];
			if(j==k||j==z||k==z) continue;
			if(j!=pos[i+1]&&k!=pos[i+1]) 
			dp[i+1][j][k]=std::min(dp[i+1][j][k],dp[i][j][k]+cost[z][pos[i+1]]);
			if(j!=pos[i+1]&&z!=pos[i+1]) 
			dp[i+1][j][z]=std::min(dp[i+1][j][z],dp[i][j][k]+cost[k][pos[i+1]]);
			if(k!=pos[i+1]&&z!=pos[i+1]) 
			dp[i+1][k][z]=std::min(dp[i+1][k][z],dp[i][j][k]+cost[j][pos[i+1]]);
		} 
		for(int j=1;j<=L;j++)
		for(int k=1;k<=L;k++)
		minn=std::min(minn,dp[n][j][k]);
		cout<<minn<<endl;
	}
	return 0;
}
