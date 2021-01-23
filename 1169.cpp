#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#define maxium 5000
using namespace std;
int n,m;
int map[maxium][maxium],le[maxium][maxium],ri[maxium][maxium],up[maxium][maxium];
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
	int res1=-0x3f3f3f3f,res2=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		if(map[i][j]!=map[i][j-1]) le[i][j]=le[i][j-1];
		for(int j=m-1;j>=1;j--)
		if(map[i][j]!=map[i][j+1]) ri[i][j]=ri[i][j+1];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i>1&&map[i][j]!=map[i-1][j]) 
		{
			le[i][j]=max(le[i][j],le[i-1][j]);
			ri[i][j]=min(ri[i][j],ri[i-1][j]);
			up[i][j]=up[i-1][j]+1;
		}
		int a=ri[i][j]-le[i][j]+1;
		int b=min(a,up[i][j]);
		res1=max(res1,b*b);
		res2=max(res2,a*up[i][j]);
	}
	cout<<res1<<"\n"<<res2;
}
int main()
{
	start();
	solve();
	return 0;
}
2 4
11
11
