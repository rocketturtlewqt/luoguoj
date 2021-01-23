#include<bits/stdc++.h>
using namespace std;
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
struct EDGE{
	int start,to,prev;
}e[maxium*2];
int head[20000],fa[20000],cnt;
inline void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
int ans,he[20000];
inline void adds(int x,int y){
	e[++ans].to=y;
	e[ans].start=x;
	e[ans].prev=he[x];
	he[x]=ans;
}
int size[20000];
inline void start(){
	n=read(),r=read(),m=read();
	fp(i,1,n-1){
		int x,y;x=read(),y=read();adds(x,y);
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
inline void solve(){
	build(r);
	fp(i,1,m){
		int sum=1,flag=0,h=0;int num[20000];
		int node;node=read();
		for(int j=he[node];j;j=e[j].prev){
			flag=1;
			int to=e[j].to;
		    num[++h]=to;
		}
		fp(j,1,h){
			fp(k,j+1,h) sum+=num[j]*num[k];
		}
		if(flag)sum*=2;
		else sum=0;
		sum+=2*size[node]-1;
		out(sum),putchar('\n');
	}
}
int main(){
	start();
	solve();
	return 0;
}
