#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
struct Node{
	int x,y;
}node[MAXN];
int n,dis[MAXN],ans[MAXN];
inline int cal(int x1,int y1,int x0,int y0){
	return abs(x1-x0)+abs(y1-y0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&node[i].x,&node[i].y);
	memset(ans,0x3f3f3f3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++) dis[k]=cal(node[k].x,node[k].y,node[i].x,node[j].y);
			sort(dis+1,dis+n+1);
			for(int k=1;k<=n;k++){
			    dis[k]+=dis[k-1];
			    ans[k]=min(ans[k],dis[k]);
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
