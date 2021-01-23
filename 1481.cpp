#include<bits/stdc++.h>
using namespace std;
int n,dp[2050];
char s[2050][100];
int main(){
	int flag,ans=-0x3f3f3f3f;cin>>n;for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
    	dp[i]=1;
    	for(int j=1;j<i;j++){
    		int len_i=strlen(s[i]),len_j=strlen(s[j]);flag=1;
    		if(len_i<len_j) flag=0;
    		for(int k=0;k<len_j;k++)
    		if(s[j][k]!=s[i][k]){flag=0;break;}
    		if(flag) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
