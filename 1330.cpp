#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
const int MAXN=4e6+5;
struct Edge{
	int to,prev;
}edge[MAXN];
int n,m,flag,cnt,ans,color[MAXN],head[MAXN];
map<int,int> book;
inline void add(int x,int y){
	edge[++cnt].to=y;edge[cnt].prev=head[x];head[x]=cnt;
}
inline void dfs(int x,int co){
	if(flag) return;
	color[x]=co;book[co]++;
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(color[to]==co) return flag=1,void();
		else if(!color[to]) dfs(to,-co);
	}
}
int main(){
	scf(n,m);
	fp(i,1,m){
		int u,v;scf(u,v);
		add(u,v);add(v,u);
	}
	fp(i,1,n){
		if(!color[i]){
			dfs(i,1);
			if(flag) return puts("Impossible"),0;
			ans+=min(book[1],book[-1]);
			book[1]=book[-1]=0; 
		}
	} 
	printf("%d\n",ans);
	return 0;
}
/*
6 7
1 2
2 3
3 4
4 5
5 6
6 1
1 4
*/
