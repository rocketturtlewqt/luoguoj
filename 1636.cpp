#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int n,m,u,v,sum,line[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		line[u]++;line[v]++;
	}
	for(int i=1;i<=n;i++) if(line[i]%2) sum++;
	if(sum==0) puts("1");
	else printf("%d\n",sum/2);
	return 0;
}
