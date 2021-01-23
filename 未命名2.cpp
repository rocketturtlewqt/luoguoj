#include<bits/stdc++.h>
using namespace std;
const int maxn=440;
struct node{
	int x,y,step;
};
int a[maxn][maxn];
int dn[maxn][maxn];
int vis[maxn][maxn];
queue<node>q;
int dir[2][8]={{1,1,-1,-1,2,2,-2,-2},{2,-2,2,-2,1,-1,1,-1}};
int n,m;
int main(){
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	node head;
	head.x=x;
	head.y=y;
	head.step=0;
	q.push(head);
	vis[x][y]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			node next=now;
			next.step++;
			next.x+=dir[0][i];
			next.y+=dir[1][i];
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&vis[next.x][next.y]==0){
				vis[next.x][next.y]=1;
				dn[next.x][next.y]=next.step;
				q.push(next);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dn[i][j]==0&&(i!=x||j!=y)){
				printf("%-5d",-1);
			}else{
				printf("%-5d",dn[i][j]);
			}
		}
		puts("");
	}
	return 0;
}
