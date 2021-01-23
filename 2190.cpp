#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 6000001
using namespace std;
int n,m;
int tx[maxium],ty[maxium];
void start()
{
	int up,down,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>up>>down>>w;
		if(down>up) tx[up]+=w;
		else 
		{
			tx[1]+=w;
			tx[up]+=w;
		}
		ty[down]+=w;
	}
}
int solve()
{
	int p=0,maxx=0;
	start();
	for(int i=1;i<=m;i++)
	{
		p+=tx[i];
		p-=ty[i];
		maxx=max(maxx,p);
	}
	if(maxx%36==0) return maxx/36;
	else return maxx/36+1;
}
int main()
{
	cout<<solve();
	return 0;
}
