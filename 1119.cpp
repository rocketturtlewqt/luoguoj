#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=205;
int n,m,q,u,v,w,t,a[MAXN],d[MAXN][MAXN];
inline void update(int k){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(d[i][j]>d[i][k]+d[k][j])
	d[i][j]=d[j][i]=d[i][k]+d[k][j];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
	    if(i!=j) d[i][j]=0x3f3f3f3f;
	    else d[i][j]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		u++;v++;
		d[u][v]=d[v][u]=w;
	}
	scanf("%d",&q);
	int now=1;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&u,&v,&t);
		u++;v++;
		while(a[now]<=t&&now<=n){
			update(now);
			now++;
		}
		if(a[u]>t||a[v]>t) puts("-1");
		else{
		    if(d[u][v]==0x3f3f3f3f) puts("-1");
		    else printf("%d\n",d[u][v]);
		}
	}
	return 0;
}
