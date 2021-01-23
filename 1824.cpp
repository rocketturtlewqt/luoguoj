#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#define maxium 200000
using namespace std;
int n,m;
int a[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
}
int judge(int x)
{
	int num=1,cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[num]>=x)
		{
			cnt++;
			num=i;
		}
	}
	return cnt>=m;
}
void erfen()
{
	int l=0,r=a[n]-a[1],ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(judge(mid)) 
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
}
int main()
{
	start();
	erfen();
	return 0;
}
