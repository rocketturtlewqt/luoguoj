#include<bits/stdc++.h>
using namespace std;
int n,nxt[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}},vis[105][105];
char s[105][105],t[7]={'y','i','z','h','o','n','g'};
inline void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<8;k++){
				int x=i+nxt[k][0]*6,
				    y=j+nxt[k][1]*6;
				if(x<1||x>n||y<1||y>n) continue;
				int flag=0;
				for(int z=0;z<7;z++){
					if(s[i+nxt[k][0]*z][j+nxt[k][1]*z]!=t[z]){
						flag=1;
						break;
					}
				} 
				if(!flag){
					for(int z=0;z<7;z++) vis[i+nxt[k][0]*z][j+nxt[k][1]*z]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]) s[i][j]='*';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>(s[i]+1);
	solve();
	for(int i=1;i<=n;i++) cout<<(s[i]+1)<<endl;
	return 0;
}
