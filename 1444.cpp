#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
struct Node{
	int x,y;
}node[15];
int n,ans,to[15],vis[15],belong[15];
bool compare(struct Node a,struct Node b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
inline int judge(int x){
	while(to[x]){
		if(vis[x]) return 1;
		vis[x]=1;
		x=belong[to[x]];
	}
	return 0;
}
inline void dfs(int x){
	if(x==n+1){
		int flag=0;
		fp(i,1,n){
			memset(vis,0,sizeof(vis));
			if(judge(i)) flag=1;
			if(flag) break;
		}
		ans+=flag;
		return;
	}
	if(belong[x]) dfs(x+1);
	else{
		fp(i,x+1,n){
			if(belong[i]) continue;
			belong[x]=i;belong[i]=x;
			dfs(x+1);
			belong[x]=belong[i]=0;
		}
	}
}
int main(){
	sc(n);
	fp(i,1,n) scf(node[i].x,node[i].y);
	sort(node+1,node+n+1,compare);
	fp(i,1,n-1) if(node[i].y==node[i+1].y) to[i]=i+1;
	dfs(1);
	printf("%d\n",ans);
	return 0; 
}
/*
8
0 0
1 0
0 1
1 1
0 2
2 2
0 3
3 3
*/
