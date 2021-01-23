#include<bits/stdc++.h>
using namespace std;
int n,m,nxt[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
char s[105][105];
inline int judge(int x,int y){
	if(x<1||x>n||y<1||y>m) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>(s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ans=0;
			if(s[i][j]=='?'){
				for(int k=0;k<8;k++){
					int tx=i+nxt[k][0];
					int ty=j+nxt[k][1];
					if(judge(tx,ty)) continue;
					if(s[tx][ty]=='*') ans++;
				}
				printf("%d",ans);
			}else{
				printf("*");
			}
		}
		puts("");
	}
	return 0;
}
