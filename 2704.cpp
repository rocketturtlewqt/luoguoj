#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[101][11],P[101][11],flag[101];
inline void start(){
	scanf("%d%d",&n,&m);
	char s[101];
	for(int i=1;i<=n;i++){
		scanf("%s",s);int ans=0;
		for(int j=1;j<=m;j++) {
			mapp[i][j]=s[j-1]=='H'?1:0;if(mapp[i][j]==1) P[i][++ans]=j;
		}
		flag[i]=ans;
	}
}
inline int judge1(int x){
	if((x&(x<<1))==0&&(x&(x<<2))==0&&(x&(x>>1))==0&&(x&(x>>2))==0) return 1;
	else return 0;
}
inline int judge2(int i,int x){
	for(int k=1;k<=flag[i];k++){
	    if(((x>>(m-P[i][k]))&1)==1) return 0;
    }
	return 1;
}
inline int lowbit(int i){
	return i&(-i);
}
inline int getsum(int x){
	int sum=0;
	while(x>0){
		sum++;x-=lowbit(x);
	}
	return sum;
}
int S[1<<11],dp[101][1<<11][1<<11],cnt;
inline void csh(){
	for(int i=0;i<=(1<<m)-1;i++)
	if(judge1(i)) S[++cnt]=i;
	for(int j=1;j<=cnt;j++) if(judge2(1,S[j])) dp[1][S[j]][0]=getsum(S[j]);
    for(int j=1;j<=cnt;j++){
    	if(judge2(2,S[j])){
    	    for(int k=1;k<=cnt;k++) 
			if(judge2(1,S[k])&&!(S[j]&S[k])){			
			    dp[2][S[j]][S[k]]=max(dp[2][S[j]][S[k]],dp[1][S[k]][0]+getsum(S[j]));
			}
		}
	}
}
inline void solve(){
	for(int i=3;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if(judge2(i,S[j]))
			for(int k=1;k<=cnt;k++){
				if(judge2(i-1,S[k])&&!(S[j]&S[k]))
				for(int l=1;l<=cnt;l++){
					if(judge2(i-2,S[l])&&!(S[j]&S[l])&&!(S[k]&S[l]))
					dp[i][S[j]][S[k]]=max(dp[i][S[j]][S[k]],dp[i-1][S[k]][S[l]]+getsum(S[j]));
				}
			}
		}
	}
	int ans=0;
	for(int j=1;j<=cnt;j++){
		if(judge2(n,S[j]))
		for(int k=1;k<=cnt;k++){
			if(judge2(n-1,S[k])&&!(S[j]&S[k])) ans=max(ans,dp[n][S[j]][S[k]]);
		}
	}
	printf("%d\n",ans);	
}
int main(){
	start();
	csh();
	solve();
	return 0;
}
