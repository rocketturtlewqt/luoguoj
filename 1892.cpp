#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 3000
using namespace std;
int n,m;
int par[maxium];
int find(int x)
{
	int r,j,k;
	r=x;
	while(r!=par[r])
	{
		r=par[r];
	}
	k=x;
	while(k!=par[k])
	{
		j=par[k];
		par[k]=r;
		k=j;
	}
	return r;
}
void init(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) par[fx]=fy;
}
void start()
{
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)
	par[i]=i;
}
void solve()
{
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		char ch;int x,y;
		cin>>ch>>x>>y;
		if(ch=='F') init(x,y);
		else
		{
			init(x+n,y);
			init(y+n,x);
		}
	}
	for(int i=1;i<=n;i++)
	if(par[i]==i) cnt++;
	cout<<cnt;
}
int main()
{
	start();
	solve();
	return 0;
}

