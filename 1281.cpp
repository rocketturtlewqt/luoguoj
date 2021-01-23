#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#define maxium 520
using namespace std;
int n,m,l=0x3f3f3f3f,r,ans;
int a[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(l,a[i]);
		r+=a[i];
	}
}
int judge(int x) 
{
	int sum=0;
	int t=1;
	for(int i=n;i>=1;i--)
	if(a[i]>x) return 0;
	for(int i=n; i>= 1;i--)
	{
        if(sum+a[i]<= x)
		sum+=a[i];
	    else
	    {
	    	t++;
	    	sum=a[i];
		}
	}
	return t<=m;
}
void solve()
{
    while(l<=r)
	{
		int mid=(l+r)>>1;
		if(judge(mid)) 
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}	
}
void print(int start,int end)
{
	int sum=0;
	for(int i=end;i>=start;i--)
	{
		if(sum+a[i]>ans)
		{
			print(start,i);
			cout<<i+1<<' '<<end<<endl;
			return;
		}		
		sum+=a[i];
	}
	cout<<1<<' '<<end<<endl;
}
int main()
{
	start();
	if(n==0) return 0;
	solve();
	print(1,n);
	return 0;
}
