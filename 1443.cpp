#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,
    nxt[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},
	     {2,1},{2,-1},{-2,1},{-2,-1}},
    mat[401][401],vis[401][401];
inline void bfs(){
	queue<pair<pair<int,int>,int> > q;
	q.push({{a,b},0});vis[a][b]=1;
	while(!q.empty()){
		int x=q.front().first.first,
		    y=q.front().first.second,
			step=q.front().second;
		q.pop();
		if(!vis[x][y]) vis[x][y]=1,mat[x][y]=step;
		for(int i=0;i<8;i++){
			int tx=x+nxt[i][0],
			    ty=y+nxt[i][1];
			if(tx<1||tx>n||ty<1||ty>m||vis[tx][ty]) continue;
			q.push({{tx,ty},step+1});
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	memset(mat,-1,sizeof(mat));
	mat[a][b]=0;
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",mat[i][j]);
		}
		puts("");
	}
	return 0;
}
