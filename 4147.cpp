#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxium 2000
using namespace std;
int n,m;
int up[maxium][maxium],le[maxium][maxium],ri[maxium][maxium];
char map[maxium][maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>map[i][j];
		up[i][j]=1;
		le[i][j]=ri[i][j]=j;
	}
}
void solve()
{
	int res=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		if(map[i][j]==map[i][j-1]) le[i][j]=le[i][j-1];
		for(int j=m-1;j>=1;j--)
		if(map[i][j]==map[i][j+1]) ri[i][j]=ri[i][j+1];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i>1&&map[i][j]==map[i-1][j])
		{
			le[i][j]=max(le[i][j],le[i-1][j]);
			ri[i][j]=min(ri[i][j],ri[i-1][j]);
			up[i][j]=up[i-1][j]+1;
		}
		if(map[i][j]=='F')
		{
		    int a=ri[i][j]-le[i][j]+1;
		    res=max(res,a*up[i][j]);
		}
	}
	cout<<res*3;
}
int main()
{
	start();
	solve();
	return 0;
}

