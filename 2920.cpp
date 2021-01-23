#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxium 5000
using namespace std;
int n,maxx;
struct Node
{
	int cost;
	int time;
}a[maxium];
bool compare(struct Node a,struct Node b)
{
	return a.time<b.time;
}
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i].cost>>a[i].time;
	    maxx=max(maxx,a[i].time);
	}
	sort(a+1,a+n+1,compare);
}
int judge(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(x+a[i].cost>a[i].time) return 0;
		x+=a[i].cost;
	}
	return 1;
}
void erfen()
{
	int l=0,r=maxx,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(judge(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(ans==-1) cout<<-1;
	else cout<<ans;
}
int main()
{
	start();
	erfen();
	return 0;
}
