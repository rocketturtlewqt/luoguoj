#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int T,size[MAXN],par[MAXN],d[MAXN];
inline int find(int x){
	if(x==par[x]) return x;
	int root=find(par[x]);
	d[x]+=d[par[x]];
	return par[x]=root;
}
inline void init(int x,int y){
	int fx=find(x),fy=find(y);
	par[fx]=fy;d[fx]+=size[fy];
	size[fy]+=size[fx];
	size[fx]=0;
}
int main(){
	cin>>T;
	for(int i=1;i<=30000;i++) size[i]=1,par[i]=i;
	while(T--){
		char c;cin>>c;
		int x,y;cin>>x>>y;
		if(c=='M') init(x,y);
		else{
			if(find(x)==find(y))cout<<abs(d[x]-d[y])-1<<endl;
			else puts("-1");
		}
	}
	return 0;
}
