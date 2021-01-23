#include<cstdio>
#include<string.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#define maxium 500050
using namespace std;
long long ans;
int n;
int a[maxium],r[maxium];
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
}
void mergesort(int s,int t)
{
	int i,j,k,m;
	if(s==t) return;
	m=(s+t)/2;
	mergesort(s,m);
	mergesort(m+1,t);
	i=s;k=s;j=m+1;
	while(i<=m&&j<=t)
	{
		if(a[i]<=a[j])
		{
			r[k]=a[i];
			i++;k++;
		}
		else 
		{
			r[k]=a[j];
			j++;k++;
			ans+=m-i+1;
		}
	}
	while(i<=m)
	{
		r[k]=a[i];k++;i++;
	}
	while(j<=t)
	{
		r[k]=a[j];k++;j++;
	}
	for(int i=s;i<=t;i++)
	a[i]=r[i];
}
void solve()
{
	mergesort(1,n);
	cout<<ans;
}
int main()
{
    start();
    solve();
    return 0;
}
void mergesort(int s,int t)
{
	int i,j,k,m;
	if(s==t) return;
	m=(s+t)/2;
	mergesort(s,m);
	mergesort(m+1,t);
	i=s;k=s;j=m+1;
	while(i<=m&&j<=t)
	{
		if(c[i]<=c[j])
		{
			b[k]=c[i];
			i++;k++;
		}
		else 
		{
			b[k]=c[j];
			j++;k++;
			ans+=m-i+1;
		}
	}
	while(i<=m)
	{
		b[k]=c[i];k++;i++;
	}
	while(j<=t)
	{
		b[k]=c[j];k++;j++;
	}
	for(int i=s;i<=t;i++)
	c[i]=b[i];
}
