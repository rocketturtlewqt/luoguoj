#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using namespace std;
#define maxium 200010
int n,par[maxium];
inline void start(){
	cin>>n;
	for(int i=1;i<=n;i++) par[i]=i;
}
inline int find(int x,int &cnt){
	cnt++;
	if(par[x]==x) return x;
	else find(par[x],cnt);
}
inline void solve(){
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		int cnt=0,f;
		cin>>f;
		if(find(f,cnt)==i) ans=min(ans,cnt);
		else par[i]=f;
	}
	printf("%d\n",ans);
}
int main(){
	start();
	solve();
	return 0;
}


