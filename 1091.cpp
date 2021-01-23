#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 105
using namespace std;
int n,pos;
int a[maxium],dp1[maxium],dp2[maxium];
void start()
{
	int maxx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
}
void solve()
{
	int maxx=0;
    for(int i=1;i<=n;i++)
    {
    	dp1[i]=1;
    	for(int j=1;j<i;j++)
    	if(a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+1);
	}
	for(int i=n;i>=1;i--)
	{
		dp2[i]=1;
		for(int j=n;j>i;j--)
		if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
	}
	for(int i=1;i<=n;i++)
	maxx=max(maxx,dp1[i]+dp2[i]-1);
	printf("%d\n",n-maxx);
}
int main()
{
	start();
	solve();
	return 0;
}
