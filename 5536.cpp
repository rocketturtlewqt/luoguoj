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
int n,k,cnt,minn,p,deep[MAXN/10],head[MAXN],f[MAXN],maxdeep[MAXN],ans[MAXN];
inline void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void dfs1(int x,int fa){
	if(minn<deep[x]){
		minn=deep[x];
		p=x;
	}
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(to==fa) continue;
		deep[to]=deep[x]+1;
		dfs1(to,x);
	}
}
inline void dfs2(int x,int fa){
	if(minn<deep[x]){
		minn=deep[x];
		p=x;
	}
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(to==fa) continue;
		deep[to]=deep[x]+1;
		f[to]=x;
		dfs2(to,x);
	}
}
inline void dfs(int x,int fa){
	maxdeep[x]=deep[x];
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(to==fa) continue;
		deep[to]=deep[x]+1;
		dfs(to,x);
		maxdeep[x]=max(maxdeep[x],maxdeep[to]);
	}
}
/*
inline void dfs1(int x,int fa){
	if(deep[x]>minn){
		minn=deep[x];
		p=x;
	}
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(fa==to) continue;
		deep[to]=deep[x]+1;
		dfs1(to,x);
	}
} 
inline void dfs2(int x,int fa){
	if(deep[x]>minn){
		minn=deep[x];
		p=x;
	}
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(fa==to) continue;
		deep[to]=deep[x]+1;
		f[to]=x;
		dfs2(to,x);
	}
}
inline void dfs(int x,int fa){
	maxdeep[x]=deep[x];
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(fa==to) continue;
		deep[to]=deep[x]+1;
		dfs(to,x);
		maxdeep[x]=max(maxdeep[x],maxdeep[to]);
	}
}
*/
int main(){
	scf(n,k);
	fp(i,1,n-1){
		int x,y;scf(x,y);
		add(x,y);add(y,x);
	}
	dfs1(1,0);
    memset(deep,0,sizeof(deep));
    minn=0;
    dfs2(p,0);
    int x=p;
    fp(i,1,(deep[p]+1)/2) x=f[x];
    memset(deep,0,sizeof(deep));
	dfs(x,0); 
	fp(i,1,n) ans[i]=maxdeep[i]-deep[i];
	sort(ans+1,ans+n+1);
	int maxx=0;
	printf("%d\n",ans[n-k]+1);
	return 0;
}
/*
#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,k,zj,cnt,maxx,num,diameter,head[2*MAXN],deep[2*MAXN],maxdeep[2*MAXN],f[2*MAXN],ans[2*MAXN];
struct Edge{
	int to,prev;
}edge[MAXN*2];
bool compare(int x,int y){
	return x>y;
}
inline void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void start(){
	scanf("%d%d",&n,&k);
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
}
inline void dfs1(int x,int fa){
	if(deep[x]>zj){
		zj=deep[x];
		num=x;
	}
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(fa==to) continue;
		deep[to]=deep[x]+1;
		dfs1(to,x);
	}
} 
inline void dfs2(int x,int fa){
	if(deep[x]>zj){
		zj=deep[x];
		num=x;
	}
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(fa==to) continue;
		deep[to]=deep[x]+1;
		f[to]=x;
		dfs2(to,x);
	}
}
inline void dfs(int x,int fa){
	maxdeep[x]=deep[x];
	for(int i=head[x];i;i=edge[i].prev){
		int to=edge[i].to;
		if(fa==to) continue;
		deep[to]=deep[x]+1;
		dfs(to,x);
		maxdeep[x]=max(maxdeep[x],maxdeep[to]);
	}
}
int main(){
	start();
	dfs1(1,0);
	memset(deep,0,sizeof(deep));
	zj=0;
	dfs2(num,0);
	int mid=num;
	for(int i=1;i<=(deep[num]+1)/2;i++) mid=f[mid];
	memset(deep,0,sizeof(deep));
	dfs(mid,0);
	for(int i=1;i<=n;i++) ans[i]=maxdeep[i]-deep[i];
	sort(ans+1,ans+n+1,compare);
	for(int i=k+1;i<=n;i++) maxx=max(maxx,ans[i]+1);
	printf("%d\n",maxx);
	return 0; 
}
*/

