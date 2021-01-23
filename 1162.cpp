#include<bits/stdc++.h>
using namespace std;
int n,mat[105][105],nxt[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
inline int judge(int x,int y){
	if(x<1||x>n||y<1||y>n) return 1;
	return 0;
}
inline void dfs(int x,int y){
	mat[x][y]=-1;
	for(int k=0;k<4;k++){
		int tx=x+nxt[k][0],
		    ty=y+nxt[k][1];
		if(judge(tx,ty)||mat[tx][ty]) continue;
		dfs(tx,ty);
	}
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&mat[i][j]);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if((i==1||i==n||j==1||j==n)&&!mat[i][j]) dfs(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%-2d",mat[i][j]==-1?0:(mat[i][j]==1?1:2));
		}
		puts("");
	}
    return 0;
}
