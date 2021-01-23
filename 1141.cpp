#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int n,m;
int map[1001][1001],f[1001][1001],h[1000001],next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[1001][1001];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	map[i][j]=a[i][j-1]-'0';
}
int judge(int x,int y)
{
	if(x<1||x>n||y<1||y>n) return 1;
	return 0;
}
void dfs(int x,int y,int num)
{
    h[num]++;
    f[x][y]=num;
    for(int i=0;i<4;i++)
    {
    	int tx=x+next[i][0];
    	int ty=y+next[i][1];
    	if(!judge(tx,ty)&&map[tx][ty]!=map[x][y]&&!f[tx][ty])
    	dfs(tx,ty,num);
	}
}
void solve()
{
	int num=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(!f[i][j]) dfs(i,j,num++);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(!f[x][y]) printf("1\n");
		else printf("%d\n",h[f[x][y]]);
	}
}
int main()
{
	start();
    solve();
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        printf("%d ",f[i][j]);
//        printf("\n");
//    }
    return 0;
}

