#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 500020
using namespace std;
int n;
int a[maxium],p[maxium],bit[maxium];
bool compare(int x,int y)
{
	return a[x]<a[y];
}
void start()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[i]=i;
	}
}
int lowerbit(int x)
{
	return x&(-x);
}
long long getsum(int x)
{
	long long res=0;
	while(x>=1)
	{
		res+=bit[x];
		x-=lowerbit(x);
	}
	return res;
}
void updata(int x)
{
	while(x<=n)
	{
		bit[x]+=1;
		x+=lowerbit(x);
	}
}
void solve()
{
	long long res=0;
	stable_sort(p+1,p+n+1,compare);
	//ШЅжи
	for(int i=1;i<=n;i++)
	{
		if(a[p[i]]!=a[p[i-1]]||i==1) a[p[i]-1]=i;
		else a[p[i]]=a[p[i]-1];
	}
	for(int i=n;i>=1;i--)
	{
		res+=getsum(a[i]-1);
		updata(a[i]);
	}
	printf("%lld\n",res); 
}
int main()
{
	start();
	solve();
	return 0;
}

