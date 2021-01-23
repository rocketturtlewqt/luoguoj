#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7;
int T,n,par[MAXN]; 
inline int find(int x){
	if(x==par[x]) return x;
	return par[x]=find(par[x]);
}
inline void init(int x,int y){
	par[find(x)]=find(y);
}
struct Node{
    int x,y,num;
}node[MAXN];
bool compare(struct Node a,struct Node b){
	return a.num>b.num;
}
int a[MAXN];
int main(){
	cin>>T;
	while(T--){
		int cnt=0;
		int flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>node[i].x>>node[i].y>>node[i].num;
			a[++cnt]=node[i].x;a[++cnt]=node[i].y;
		}
		sort(a+1,a+cnt+1);
		int m=unique(a+1,a+cnt+1)-a-1;
		for(int i=1;i<=n;i++){
			node[i].x=lower_bound(a+1,a+m+1,node[i].x)-a;
			node[i].y=lower_bound(a+1,a+m+1,node[i].y)-a;
		}
		for(int i=1;i<=m;i++) par[i]=i;
		sort(node+1,node+n+1,compare);
		for(int i=1;i<=n;i++){
			int x=node[i].x,y=node[i].y;
            if(node[i].num){
            	if(find(x)==find(y)) continue;
            	init(x,y);
			}
			else{
				if(find(x)==find(y)){
					flag=0;
					puts("NO");
					break;
				}
			}	
		}
		if(flag) puts("YES");
	}
	return 0;
}

