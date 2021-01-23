#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxium 2000000
using namespace std;
typedef long long ll;
int n,m;
ll maxx;
ll h[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>h[i];
	    maxx=max(maxx,h[i]);
	}
}
int judge(ll x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	if(x<h[i]) sum+=h[i]-x;
	return sum>=m;
}
void erfen()
{
	ll l=0,r=maxx,ans;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(judge(mid)) 
		{
			ans=mid;
			l=mid+1;
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
