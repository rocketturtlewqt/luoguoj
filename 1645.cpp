#include<cstdio>
#include<iostream>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 2000
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
struct Edge{
	int l,r,w;
}edge[maxium];
inline bool compare(struct Edge a,struct Edge b){
	return a.r<b.r;
}
int n;
int vis[maxium];
#define fp(i,w,n) for(int i=w;i<=n;i++)
#define fd(i,w,n) for(int i=w;i>=n;i--)
inline void start(){
	n=read();
	fp(i,1,n) edge[i].l=read(),edge[i].r=read(),edge[i].w=read();
	sort(edge+1,edge+n+1,compare);
}
inline void solve(){
	int cnt,ans=0;
	fp(i,1,n){
		cnt=0;
		fp(j,edge[i].l,edge[i].r) if(vis[j]) cnt++;
		if(cnt<edge[i].w) fd(j,edge[i].r,edge[i].l) {if(!vis[j])vis[j]=1,cnt++,ans++;if(cnt==edge[i].w) break;}
	}
	out(ans),putchar('\n');
}
int main()
{
	start();solve();return 0;
}

