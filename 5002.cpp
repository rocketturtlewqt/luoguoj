#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
int n,r,m;
#define maxium 60000
#define fp(i,w,n) for(int i=w;i<=n;i++)
struct Edge{
	int to,prev;
}edge[maxium*2];
int head[20000],fa[20000],cnt;
inline void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
int size[20000];
inline void start(){
	n=read(),r=read(),m=read();
	fp(i,1,n-1){
		int x,y;x=read(),y=read();
		add(x,y);add(y,x);
	}
	fp(i,1,n) fa[i]=i;
	size[r]=1;
}
inline void dfs(int temp){
	for(int i=head[temp];i;i=edge[i].prev){
		int to=edge[i].to;if(to==fa[temp]) continue;fa[to]=temp;
		dfs(to);size[to]++;size[temp]+=size[to];
	}
}
inline void build(int root){
	dfs(root);
}
ll Ans[20000];
const int Mod=1e9+7;
inline void solve(){
	build(r);
    fp(i,1,m){
    	int p=read();
    	if(Ans[p]!=0) {printf("%lld\n",Ans[p]);continue;}
    	int size_rest;
    	ll num=size[p]*2-1;
    	for(int j=head[p];j;j=edge[j].prev){
    		int to=edge[j].to;
    		if(to==fa[p]) continue;
    		size_rest=size[p]-size[to]-1;
    		num=(num+(size_rest*size[to]))%Mod;
		}
		Ans[p]=num;
		printf("%lld\n",num);
	}
}
int main(){
	start();
	solve();
	return 0;
}

