#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 50001
using namespace std;
int n,m;
int h[maxium],lg[maxium],stmax[maxium][100],stmin[maxium][100];
void init()
{
	lg[0]=-1;
	for(int i=1;i<=2*n;i++)
	lg[i]=lg[i>>1]+1;
}
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>h[i];
	init();
}
void ST1()
{
	for(int i=1;i<=n;i++)
	stmax[i][0]=h[i];
	for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
}
void ST2()
{
	for(int i=1;i<=n;i++)
	stmin[i][0]=h[i];
	for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
}
int RMQmax(int l,int r)
{
	int k=lg[r-l+1];
	return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
}
int RMQmin(int l,int r)
{
	int k=lg[r-l+1];
	return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
}

void solve()
{
	ST1();ST2();
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		printf("%d\n",RMQmax(u,v)-RMQmin(u,v));
	}
}
int main()
{
	start();
	solve();
	return 0;
}
