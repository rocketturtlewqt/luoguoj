#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 1000000
using namespace std;
int n,m,maxx;
int a[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    maxx+=a[i];
	}
}
int judge(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
    sum+=a[i]/x;
    return sum>=m;
}
void erfen()
{
	int l=0,r=maxx,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(mid==0) break;
		if(judge(mid)) 
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
    }
	if(ans<1) cout<<"0";
	else cout<<ans;
}
int main()
{
	start();
	erfen();
	return 0;
}

