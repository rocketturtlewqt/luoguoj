#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 40000
using namespace std;
int n;
int bit[maxium],t1[maxium],t2[maxium],a[maxium];
struct Node
{
	long num;
	int pos;
}node[maxium];
bool compare(struct Node a,struct Node b)
{
	return a.num<b.num;
}
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>node[i].num;
	    node[i].pos=i;
	}
}
int lowbit(int x)
{
	return x&(-x);
}
void updata(int x)
{
	while(x<=n)
	{
		bit[x]+=1;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int sum=0;
	while(x>=1)
	{
		sum+=bit[x];
		x-=lowbit(x);
	}
	return sum;
}
void solve()
{
	long sum=0;
	start();
	sort(node+1,node+n+1,compare);
	for(int i=1;i<=n;i++)
	{
		if(node[i].num!=node[i-1].num||i==1) a[node[i].pos]=i;
		else a[node[i].pos]=a[node[i-1].pos];
	}
	for(int i=1;i<=n;i++)
	{
		t1[i]=getsum(a[i]-1);
		updata(a[i]);
	}
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;i--)
	{
		t2[i]=getsum(n-a[i]);
		updata(n-a[i]+1);
	}
	for(int i=1;i<=n;i++)
	sum+=t1[i]*t2[i];
	cout<<sum;
}
int main()
{
	solve();
	return 0;
}

