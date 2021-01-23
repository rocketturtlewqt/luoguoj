#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 10050
using namespace std;
int n,m;
int par[3*maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=3*n;i++)
	par[i]=i;
}
int find(int x)
{
	int j,r,k;
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
void solve()
{
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int num,x,y;
		cin>>num>>x>>y;
		if(x>n||y>n) 
		{
			cnt++;
			continue;
		}
		if(num==1) 
		{
			if(find(x+n)==find(y)||find(y+n)==find(x)) cnt++;
			else 
			{
				init(x,y);
				init(x+n,y+n);
				init(x+n+n,y+n+n);
			}
		}
		if(num==2)
		{
			if(x==y) cnt++;
	        else if(find(x)==find(y)||find(x)==find(y+n)) cnt++;
	        else
	        {
	        	init(x+n,y);
	        	init(x+n+n,y+n);
	        	init(x,y+n+n);
			}
		} 
	}
	cout<<cnt;
}
int main()
{
	start();
	solve();
	return 0;
}
