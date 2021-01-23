#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 1020
using namespace std;
int n,m,flag;
int p[maxium][maxium],next[4][2]={{0,1},{1,0},{0,-1},{-1,0}},vis[maxium][maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>p[i][j];
}
int judge(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return 1;
	return 0;
}
void dfs(int x,int y,int mid)
{
	if(x==n) 
	{
		flag=1;
		return;
	}
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int tx=x+next[i][0];
		int ty=y+next[i][1];
		if(!judge(tx,ty)&&!vis[tx][ty]&&p[tx][ty]<=mid)
		{
            dfs(tx,ty,mid);
			if(flag) return; 
		}
	}
}
void solve()
{
	int l=0;
	int r=1008;
	while(l<=r)
	{
		memset(vis,0,sizeof(vis));
		flag=0;
		int mid=(l+r)>>1;
		dfs(1,1,mid);
		if(flag==1) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
}
int main()
{
	start();
	solve();
	return 0;
}
